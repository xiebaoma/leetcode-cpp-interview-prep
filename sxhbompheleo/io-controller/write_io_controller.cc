#include "write_io_controller.h"
#include <chrono>
#include <thread>

namespace spdb::sdk::io {

WriteIOController::WriteIOController() : write_count_(0), write_banned_(false) {}

bool WriteIOController::try_start_write(bool block_on_ban, int timeout_ms) {
    auto start_time = std::chrono::steady_clock::now();
    auto timeout_duration = std::chrono::milliseconds(timeout_ms);

    while (true) {
        // 如果当前处于禁写状态
        if (write_banned_.load(std::memory_order_acquire)) {
            if (!block_on_ban) {
                // 不阻塞，直接返回false
                DLOG(INFO) << "[WriteIOController] try_start_write: write_banned, not block mode";
                return false;
            }

            // 阻塞等待，检查是否超时
            if (timeout_ms > 0) {
                auto current_time = std::chrono::steady_clock::now();
                if (current_time - start_time >= timeout_duration) {
                    LOG(WARNING) << "[WriteIOController] try_start_write: timeout";
                    return false;  // 超时
                }
            }

            // 睡眠一段时间后重试
            DLOG(INFO) << "[WriteIOController] try_start_write: write not ready, try again";
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_INTERVAL_MS));
            continue;
        }

        // 原子地增加写操作计数
        write_count_.fetch_add(1, std::memory_order_acq_rel);

        // 双重检查：增加计数后再次检查是否被禁写
        // 这是为了防止在增加计数的同时开始禁写的竞争条件
        if (write_banned_.load(std::memory_order_acquire)) {
            // 如果已经被禁写，需要撤销刚才的计数增加
            write_count_.fetch_sub(1, std::memory_order_acq_rel);

            if (!block_on_ban) {
                DLOG(INFO) << "[WriteIOController] try_start_write: write_banned, not block mode";
                return false;
            }

            // 阻塞等待，检查是否超时
            if (timeout_ms > 0) {
                auto current_time = std::chrono::steady_clock::now();
                if (current_time - start_time >= timeout_duration) {
                    LOG(WARNING) << "[WriteIOController] try_start_write: timeout";
                    return false;  // 超时
                }
            }

            // 睡眠一段时间后重试
            DLOG(INFO) << "[WriteIOController] try_start_write: write not ready, try again";
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_INTERVAL_MS));
            continue;
        }

        // 成功开始写操作
        DLOG(INFO) << "[WriteIOController] try_start_write: success, now write count: " << write_count_.load(std::memory_order_acquire);
        return true;
    }
}

bool WriteIOController::start_write_blocking(int timeout_ms) {
    return try_start_write(true, timeout_ms);
}

void WriteIOController::end_write() {
    // 原子地减少写操作计数
    int prev_count = write_count_.fetch_sub(1, std::memory_order_acq_rel);

    // 检查计数是否合法（防止错误的调用）
    if (prev_count <= 0) {
        // 在实际使用中，这里可能需要记录错误或抛出异常
        // 这里我们简单地将计数设置为0
        write_count_.store(0, std::memory_order_release);
    }
}

void WriteIOController::start_write_ban() {
    // 原子地设置禁写标志
    write_banned_.store(true, std::memory_order_release);
}

bool WriteIOController::wait_all_writes_complete(int timeout_ms) {
    if (timeout_ms == 0) {
        // 无限等待
        while (write_count_.load(std::memory_order_acquire) > 0) {
            DLOG(INFO) << "[WriteIOController] wait_all_writes_complete, now write count: " << write_count_.load(std::memory_order_acquire);
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_INTERVAL_MS));
        }
        return true;
    }
    // 有超时限制的等待
    auto start_time = std::chrono::steady_clock::now();
    auto timeout_duration = std::chrono::milliseconds(timeout_ms);

    while (write_count_.load(std::memory_order_acquire) > 0) {
        auto current_time = std::chrono::steady_clock::now();
        if (current_time - start_time >= timeout_duration) {
            return false;  // 超时
        }
        DLOG(INFO) << "[WriteIOController] wait_all_writes_complete, now write count: " << write_count_.load(std::memory_order_acquire);
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_INTERVAL_MS));
    }
    return true;
}

void WriteIOController::resume_write() {
    // 原子地清除禁写标志
    write_banned_.store(false, std::memory_order_release);
}

int WriteIOController::get_write_count() const {
    return write_count_.load(std::memory_order_acquire);
}

bool WriteIOController::is_write_banned() const {
    return write_banned_.load(std::memory_order_acquire);
}

const char* WriteIOController::get_controller_type() const {
    return "WriteIOController";
}

} // namespace spdb::sdk::io
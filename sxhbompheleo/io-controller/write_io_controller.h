#pragma once

#include "io_controller.h"
#include <atomic>
#include <chrono>
#include <glog/logging.h>
#include <mutex>
#include <thread>

namespace spdb::sdk::io {

/**
 * @brief WriteIOController - 线程安全的写IO计数与控制模块
 *
 * 功能：
 * 1. 记录当前进行中的写IO操作数量
 * 2. 提供禁写机制，用于快照复制时的一致性保证
 * 3. 等待所有写IO操作完成后才允许快照操作
 * 4. 支持恢复写操作
 */
class WriteIOController : public IOController {
public:
    WriteIOController();
    ~WriteIOController() override = default;

    /**
     * @brief 尝试开始一个写操作
     * @param block_on_ban 是否在禁写时阻塞等待（默认false）
     * @param timeout_ms 阻塞等待的超时时间（毫秒），0表示无限等待（默认0）
     * @return true: 成功开始写操作，IO计数+1
     *         false: 当前处于禁写状态且不阻塞，或阻塞超时
     */
    bool try_start_write(bool block_on_ban = false, int timeout_ms = 0) override;

    /**
     * @brief 开始一个写操作（阻塞版本）
     * 如果当前处于禁写状态，会阻塞等待直到禁写解除
     * @param timeout_ms 阻塞等待的超时时间（毫秒），0表示无限等待（默认0）
     * @return true: 成功开始写操作，IO计数+1
     *         false: 阻塞超时
     */
    bool start_write_blocking(int timeout_ms = 0) override;

    /**
     * @brief 结束一个写操作
     * 将IO计数-1
     */
    void end_write() override;

    /**
     * @brief 开始禁写操作
     * 设置禁写标志，新的写操作将被拒绝
     */
    void start_write_ban() override;

    /**
     * @brief 等待所有写操作完成
     * 阻塞直到IO计数变为0
     * @param timeout_ms 超时时间（毫秒），0表示无限等待
     * @return true: 所有写操作已完成
     *         false: 超时
     */
    bool wait_all_writes_complete(int timeout_ms = 0) override;

    /**
     * @brief 恢复写操作
     * 清除禁写标志，允许新的写操作
     */
    void resume_write() override;

    /**
     * @brief 获取当前写操作计数
     * @return 当前进行中的写操作数量
     */
    int get_write_count() const override;

    /**
     * @brief 检查是否处于禁写状态
     * @return true: 禁写状态
     *         false: 允许写状态
     */
    bool is_write_banned() const override;

    /**
     * @brief 获取IO控制器类型名称
     * @return 控制器类型字符串
     */
    const char* get_controller_type() const override;

private:
    // 当前进行中的写IO操作数量
    std::atomic<int> write_count_ = 0;

    // 是否禁止写操作
    std::atomic<bool> write_banned_ = false;

    // 睡眠间隔（毫秒）
    static constexpr int SLEEP_INTERVAL_MS = 100;
};

} // namespace spdb::sdk::io
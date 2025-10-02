//
// Created by yingzhi.mao on 2025/7/22.
//

#include "write_io_controller.h"

#include <atomic>  // Added for atomic operations
#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

// 简单的断言宏
#define ASSERT_TRUE(condition)                                                                   \
    if (!(condition)) {                                                                          \
        std::cout << "ASSERTION FAILED: " << #condition << " at line " << __LINE__ << std::endl; \
        return false;                                                                            \
    }

#define ASSERT_FALSE(condition)                                                                    \
    if (condition) {                                                                               \
        std::cout << "ASSERTION FAILED: " << #condition << " should be false at line " << __LINE__ \
                  << std::endl;                                                                    \
        return false;                                                                              \
    }

#define ASSERT_EQ(expected, actual)                                                         \
    if ((expected) != (actual)) {                                                           \
        std::cout << "ASSERTION FAILED: expected " << (expected) << " but got " << (actual) \
                  << " at line " << __LINE__ << std::endl;                                  \
        return false;                                                                       \
    }

// 测试基本功能
bool test_basic_functionality() {
    std::cout << "测试基本功能..." << std::endl;

    spdb::sdk::io::WriteIOController controller;

    // 初始状态检查
    ASSERT_EQ(0, controller.get_write_count());
    ASSERT_FALSE(controller.is_write_banned());

    // 测试开始写操作
    ASSERT_TRUE(controller.try_start_write());
    ASSERT_EQ(1, controller.get_write_count());

    // 测试结束写操作
    controller.end_write();
    ASSERT_EQ(0, controller.get_write_count());

    // 测试禁写
    controller.start_write_ban();
    ASSERT_TRUE(controller.is_write_banned());
    ASSERT_FALSE(controller.try_start_write());
    ASSERT_EQ(0, controller.get_write_count());

    // 测试恢复写操作
    controller.resume_write();
    ASSERT_FALSE(controller.is_write_banned());
    ASSERT_TRUE(controller.try_start_write());
    ASSERT_EQ(1, controller.get_write_count());

    controller.end_write();

    std::cout << "基本功能测试通过!" << std::endl;
    return true;
}

// 测试RAII Guard
bool test_raii_guard() {
    std::cout << "测试RAII Guard..." << std::endl;

    spdb::sdk::io::WriteIOController controller;

    // 正常情况
    {
        spdb::sdk::io::IOGuard guard(controller);
        ASSERT_TRUE(guard.is_valid());
        ASSERT_EQ(1, controller.get_write_count());
    }
    ASSERT_EQ(0, controller.get_write_count());

    // 禁写情况
    controller.start_write_ban();
    {
        spdb::sdk::io::IOGuard guard(controller);
        ASSERT_FALSE(guard.is_valid());
        ASSERT_EQ(0, controller.get_write_count());
    }
    ASSERT_EQ(0, controller.get_write_count());

    controller.resume_write();

    std::cout << "RAII Guard测试通过!" << std::endl;
    return true;
}

// 测试并发写操作
bool test_concurrent_writes() {
    std::cout << "测试并发写操作..." << std::endl;

    spdb::sdk::io::WriteIOController controller;
    const int thread_count = 10;
    const int operations_per_thread = 100;

    std::vector<std::thread> threads;
    std::atomic<int> success_count(0);

    // 创建多个线程同时进行写操作
    for (int i = 0; i < thread_count; ++i) {
        threads.emplace_back([&controller, &success_count, operations_per_thread]() {
            for (int j = 0; j < operations_per_thread; ++j) {
                if (controller.try_start_write()) {
                    success_count.fetch_add(1);
                    // 模拟短暂的写操作
                    std::this_thread::sleep_for(std::chrono::microseconds(10));
                    controller.end_write();
                }
            }
        });
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    // 验证最终状态
    ASSERT_EQ(0, controller.get_write_count());
    ASSERT_EQ(thread_count * operations_per_thread, success_count.load());

    std::cout << "并发写操作测试通过!" << std::endl;
    return true;
}

// 测试快照流程
bool test_snapshot_flow() {
    std::cout << "测试快照流程..." << std::endl;

    spdb::sdk::io::WriteIOController controller;
    std::atomic<bool> all_writes_done(false);
    std::atomic<int> rejected_writes(0);

    // 启动写操作线程
    std::thread writer_thread([&controller, &all_writes_done, &rejected_writes]() {
        for (int i = 0; i < 1000; ++i) {
            if (controller.try_start_write()) {
                // 模拟写操作
                std::this_thread::sleep_for(std::chrono::microseconds(100));
                controller.end_write();
            } else {
                rejected_writes.fetch_add(1);
                std::this_thread::sleep_for(std::chrono::microseconds(10));
            }
        }
        all_writes_done.store(true);
    });

    // 等待一些写操作开始
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    // 开始快照流程
    controller.start_write_ban();

    // 等待所有写操作完成
    bool wait_success = controller.wait_all_writes_complete(1000);  // 1秒超时
    ASSERT_TRUE(wait_success);
    ASSERT_EQ(0, controller.get_write_count());

    // 模拟快照复制
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    // 恢复写操作
    controller.resume_write();

    // 等待写线程完成
    writer_thread.join();

    // 验证有写操作被拒绝
    ASSERT_TRUE(rejected_writes.load() > 0);

    std::cout << "快照流程测试通过!" << std::endl;
    return true;
}

// 测试超时功能
bool test_timeout() {
    std::cout << "测试超时功能..." << std::endl;

    spdb::sdk::io::WriteIOController controller;

    // 启动一个长时间的写操作
    ASSERT_TRUE(controller.try_start_write());

    std::thread long_write_thread([&controller]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        controller.end_write();
    });

    // 测试短超时
    bool timeout_result = controller.wait_all_writes_complete(100);  // 100ms超时
    ASSERT_FALSE(timeout_result);

    // 测试长超时
    timeout_result = controller.wait_all_writes_complete(1000);  // 1秒超时
    ASSERT_TRUE(timeout_result);

    long_write_thread.join();

    std::cout << "超时功能测试通过!" << std::endl;
    return true;
}

int main() {
    std::cout << "开始WriteIOController单元测试\n" << std::endl;

    bool all_passed = true;

    all_passed &= test_basic_functionality();
    all_passed &= test_raii_guard();
    all_passed &= test_concurrent_writes();
    all_passed &= test_snapshot_flow();
    all_passed &= test_timeout();

    if (all_passed) {
        std::cout << "\n所有测试通过! ✓" << std::endl;
        return 0;
    } else {
        std::cout << "\n有测试失败! ✗" << std::endl;
        return 1;
    }
}

// 编译命令:
// g++ -std=c++11 -pthread write_io_controller.cc write_io_controller_test.cc -o
// write_io_controller_test

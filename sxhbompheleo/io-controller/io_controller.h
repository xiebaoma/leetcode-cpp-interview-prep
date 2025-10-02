#pragma once

#include <atomic>
#include <chrono>

namespace spdb::sdk::io {

/**
 * @brief IO控制器抽象基类
 * 
 * 提供统一的IO操作控制接口，支持不同的实现策略：
 * - WriteIOController: 实际的写IO控制和禁写功能
 * - NullIOController: 空实现，不进行任何控制
 */
class IOController {
public:
    virtual ~IOController() = default;

    /**
     * @brief 尝试开始一个写操作
     * @param block_on_ban 是否在禁写时阻塞等待（默认false）
     * @param timeout_ms 阻塞等待的超时时间（毫秒），0表示无限等待（默认0）
     * @return true: 成功开始写操作，IO计数+1
     *         false: 当前处于禁写状态且不阻塞，或阻塞超时
     */
    virtual bool try_start_write(bool block_on_ban = false, int timeout_ms = 0) = 0;

    /**
     * @brief 开始一个写操作（阻塞版本）
     * 如果当前处于禁写状态，会阻塞等待直到禁写解除
     * @param timeout_ms 阻塞等待的超时时间（毫秒），0表示无限等待（默认0）
     * @return true: 成功开始写操作，IO计数+1
     *         false: 阻塞超时
     */
    virtual bool start_write_blocking(int timeout_ms = 0) = 0;

    /**
     * @brief 结束一个写操作
     * 将IO计数-1
     */
    virtual void end_write() = 0;

    /**
     * @brief 开始禁写操作
     * 设置禁写标志，新的写操作将被拒绝
     */
    virtual void start_write_ban() = 0;

    /**
     * @brief 等待所有写操作完成
     * 阻塞直到IO计数变为0
     * @param timeout_ms 超时时间（毫秒），0表示无限等待
     * @return true: 所有写操作已完成
     *         false: 超时
     */
    virtual bool wait_all_writes_complete(int timeout_ms = 0) = 0;

    /**
     * @brief 恢复写操作
     * 清除禁写标志，允许新的写操作
     */
    virtual void resume_write() = 0;

    /**
     * @brief 获取当前写操作计数
     * @return 当前进行中的写操作数量
     */
    virtual int get_write_count() const = 0;

    /**
     * @brief 检查是否处于禁写状态
     * @return true: 禁写状态
     *         false: 允许写状态
     */
    virtual bool is_write_banned() const = 0;

    /**
     * @brief 获取IO控制器类型名称
     * @return 控制器类型字符串
     */
    virtual const char* get_controller_type() const = 0;
};

/**
 * @brief RAII辅助类，用于自动管理写操作的开始和结束
 */
class IOGuard {
public:
    /**
     * @brief 构造函数
     * @param controller IOController实例
     * @param block_on_ban 是否在禁写时阻塞等待（默认false）
     * @param timeout_ms 阻塞等待的超时时间（毫秒），0表示无限等待（默认0）
     */
    explicit IOGuard(IOController& controller, bool block_on_ban = false, int timeout_ms = 0);

    /**
     * @brief 创建阻塞版本的IOGuard
     * @param controller IOController实例
     * @param timeout_ms 阻塞等待的超时时间（毫秒），0表示无限等待（默认0）
     * @return 阻塞版本的IOGuard实例
     */
    static IOGuard blocking(IOController& controller, int timeout_ms = 0);

    /**
     * @brief 析构函数
     * 自动调用end_write()
     */
    ~IOGuard();

    /**
     * @brief 检查是否成功获取了写权限
     * @return true: 成功获取写权限
     *         false: 未获取写权限（禁写状态）
     */
    bool is_valid() const;

    // 禁止拷贝和赋值
    IOGuard(const IOGuard&) = delete;
    IOGuard& operator=(const IOGuard&) = delete;

private:
    IOController& controller_;
    bool valid_;
};

} // namespace spdb::sdk::io
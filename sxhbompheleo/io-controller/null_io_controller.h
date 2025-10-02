#pragma once

#include "io_controller.h"

namespace spdb::sdk::io {

/**
 * @brief NullIOController - 空实现的IO控制器
 *
 * 特性：
 * 1. 不进行任何实际的IO控制
 * 2. 所有写操作都立即成功
 * 3. 禁写操作不会产生实际效果
 * 4. 用于测试环境或不需要IO控制的场景
 */
class NullIOController : public IOController {
public:
    NullIOController() = default;
    ~NullIOController() override = default;

    /**
     * @brief 尝试开始一个写操作（空实现，总是成功）
     * @param block_on_ban 忽略，不阻塞
     * @param timeout_ms 忽略，无需等待
     * @return 总是返回true
     */
    bool try_start_write(bool block_on_ban = false, int timeout_ms = 0) override;

    /**
     * @brief 开始一个写操作（空实现，总是成功）
     * @param timeout_ms 忽略，无需等待
     * @return 总是返回true
     */
    bool start_write_blocking(int timeout_ms = 0) override;

    /**
     * @brief 结束一个写操作（空实现）
     */
    void end_write() override;

    /**
     * @brief 开始禁写操作（空实现，不产生效果）
     */
    void start_write_ban() override;

    /**
     * @brief 等待所有写操作完成（空实现，立即返回）
     * @param timeout_ms 忽略，无需等待
     * @return 总是返回true
     */
    bool wait_all_writes_complete(int timeout_ms = 0) override;

    /**
     * @brief 恢复写操作（空实现）
     */
    void resume_write() override;

    /**
     * @brief 获取当前写操作计数（空实现，总是返回0）
     * @return 总是返回0
     */
    int get_write_count() const override;

    /**
     * @brief 检查是否处于禁写状态（空实现，总是返回false）
     * @return 总是返回false
     */
    bool is_write_banned() const override;

    /**
     * @brief 获取IO控制器类型名称
     * @return 控制器类型字符串
     */
    const char* get_controller_type() const override;
};

} // namespace spdb::sdk::io
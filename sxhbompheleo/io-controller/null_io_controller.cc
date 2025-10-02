#include "null_io_controller.h"

namespace spdb::sdk::io {

bool NullIOController::try_start_write(bool block_on_ban, int timeout_ms) {
    // 空实现，总是成功
    return true;
}

bool NullIOController::start_write_blocking(int timeout_ms) {
    // 空实现，总是成功
    return true;
}

void NullIOController::end_write() {
    // 空实现，什么也不做
}

void NullIOController::start_write_ban() {
    // 空实现，不产生禁写效果
}

bool NullIOController::wait_all_writes_complete(int timeout_ms) {
    // 空实现，立即返回成功
    return true;
}

void NullIOController::resume_write() {
    // 空实现，什么也不做
}

int NullIOController::get_write_count() const {
    // 空实现，总是返回0
    return 0;
}

bool NullIOController::is_write_banned() const {
    // 空实现，总是返回false（未禁写）
    return false;
}

const char* NullIOController::get_controller_type() const {
    return "NullIOController";
}

} // namespace spdb::sdk::io
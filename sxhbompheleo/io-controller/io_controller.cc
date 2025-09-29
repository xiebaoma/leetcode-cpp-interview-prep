#include "io_controller.h"

namespace spdb::sdk::io {

// IOGuard 实现
IOGuard::IOGuard(IOController& controller, bool block_on_ban, int timeout_ms)
    : controller_(controller), valid_(false) {
    valid_ = controller_.try_start_write(block_on_ban, timeout_ms);
}

IOGuard IOGuard::blocking(IOController& controller, int timeout_ms) {
    return IOGuard(controller, true, timeout_ms);
}

IOGuard::~IOGuard() {
    if (valid_) {
        controller_.end_write();
    }
}

bool IOGuard::is_valid() const { 
    return valid_; 
}

} // namespace spdb::sdk::io
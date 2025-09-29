cmake_minimum_required(VERSION 3.28)
project(write_io_controller_test)

set(CMAKE_CXX_STANDARD 20)

# Homebrew 安装路径
set(GLOG_ROOT /opt/homebrew/opt/glog)
set(GFLAGS_ROOT /opt/homebrew/opt/gflags)

set(SOURCES
    write_io_controller_test.cpp
    write_io_controller.cc
    io_controller.cc
)

set(HEADERS
    write_io_controller.h
)

add_executable(write_io_controller_test ${SOURCES} ${HEADERS})

# 添加头文件路径
target_include_directories(write_io_controller_test PRIVATE
    ${GLOG_ROOT}/include
    ${GFLAGS_ROOT}/include
)

# 链接库
target_link_libraries(write_io_controller_test PRIVATE
    ${GLOG_ROOT}/lib/libglog.dylib
    ${GFLAGS_ROOT}/lib/libgflags.dylib
)

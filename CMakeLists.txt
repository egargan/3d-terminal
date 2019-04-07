cmake_minimum_required(VERSION 3.12)
project(3dterm)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

# https://github.com/bast/gtest-demo

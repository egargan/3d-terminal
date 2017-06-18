cmake_minimum_required(VERSION 3.6)
project(3dConsole)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(3dConsole ${SOURCE_FILES})

target_link_libraries(3dConsole ${CURSES_LIBRARIES})

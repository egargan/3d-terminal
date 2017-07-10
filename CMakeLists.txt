cmake_minimum_required(VERSION 3.6)
project(3dTerminal)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Model.h Model.cpp Graphics.cpp Graphics.h World.cpp World.h Vec3.cpp Vec3.h Mat3.cpp Mat3.h)
add_executable(3dTerminal ${SOURCE_FILES})

target_link_libraries(3dTerminal ${CURSES_LIBRARIES})

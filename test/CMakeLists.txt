project(${CMAKE_PROJECT_NAME}_test)

add_subdirectory("${CMAKE_SOURCE_DIR}/lib/googletest" "lib/googletest")
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(unitTests main.cc obj_import_test.cc)

target_link_libraries(unitTests gtest gtest_main)

include_directories(${CMAKE_SOURCE_DIR}/src)


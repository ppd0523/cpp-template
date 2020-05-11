cmake_minimum_required(VERSION 3.0)

project(runTest)

add_executable(runTest test.cpp)
target_link_libraries(runTest gtest_main)

add_test(
    NAME testing
    COMMAND testing
)
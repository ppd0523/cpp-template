cmake_minimum_required(VERSION 3.0)

project(cpp-templete)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    include
)

add_subdirectory(lib/spdlog)
add_subdirectory(lib/googletest)
add_subdirectory(test)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} spdlog)
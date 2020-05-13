cmake_minimum_required(VERSION 3.5)

project(cpp-templete)

# Common build option
# set(CMAKE_C_COMPILER "/usr/bin/gcc")  # 컴파일러
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")  # 컴파일러

add_compile_options(-Wall -static -Wl,--gc-sections)
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_C_STANDARD 99)    # C 표준
set(CMAKE_CXX_STANDARD 14)  # CXX 표준
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# 공통 링크 라이브러리 -l
# link_libraries(usart andromeda)

# 공통 링크 라이브러리 패스 -L
# link_directories(/usr/lib)

# -I
include_directories(
    include
)

# Debug 빌드 한정 컴파일, 링크 옵션
set(CMAKE_C_FLAGS_DEBUG "-DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "")

# Release 빌드 한정 컴파일, 링크 옵션
set(CMAKE_C_FLAGS_RELEASE "-DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "")

add_subdirectory(lib/spdlog)
add_subdirectory(lib/googletest)
add_subdirectory(test)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} spdlog)

# Output directory
SET(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib)
SET(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib/static)
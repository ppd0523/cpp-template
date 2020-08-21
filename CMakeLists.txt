cmake_minimum_required(VERSION 3.5)

project(cpp-template)

# Build debugging
# 만일 CMAKE_VERBOSE_MAKEFILE 이면 true(or 1), makefile 빌드 메세지를 상세히 출력
# project() 명령은 항상 CMAKE_VERBOSE_MAKEFILE를 false(OFF)로 초기화 함
SET(CMAKE_VERBOSE_MAKEFILE ON)

# Common build option
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")  # 컴파일러
add_compile_options(-Wall -Wl,--gc-sections,-static)
set(CMAKE_EXE_LINKER_FLAGS "") # -Wl,--gc-sections,-static
set(CMAKE_CXX_STANDARD 14)  # CXX 표준
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Output directory
SET(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib)
SET(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib/static)

# 공통 링크 라이브러리 -l
# link_libraries(usart andromeda)

# 공통 링크 라이브러리 패스 -L
# link_directories(/usr/lib)

# -I
include_directories(
    include
)

# Debug 빌드 한정 컴파일, 링크 옵션
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "")

# Release 빌드 한정 컴파일, 링크 옵션
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "")

add_subdirectory(lib/spdlog)

# ---------- Build Excutable ----------
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} spdlog)

# ---------- Build Test ---------------
option(CMAKE_GTEST "Build the test" ON)
if(CMAKE_GTEST)
    enable_testing()
    add_subdirectory(lib/googletest)
    add_subdirectory(test)
endif()



# TIP
# $ cmake --build <path>
# <path>에 빌드한다.
#
# $ cmake install
# install(...) 고정 경로에 파일들을 복사하는 함수

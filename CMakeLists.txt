cmake_minimum_required(VERSION 3.10.0)
project(mini_shell VERSION 0.1.0 LANGUAGES C CXX)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP FALSE
)

set(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/main.c
    src/init.c
    src/utils.c
    src/parser.c
    src/builtin.c
    src/executor.c)

set(HEADERS
    include/init.h
    include/utils.h
    include/parser.h
    include/builtin.h
    include/executor.h)

set(TEST
    test/ut_utils.cpp)

include_directories(include)

add_executable(mini_shell ${SOURCES})

add_executable(ututils ${TEST} src/utils.c)

target_link_libraries(ututils gtest gtest_main)

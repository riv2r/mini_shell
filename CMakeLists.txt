cmake_minimum_required(VERSION 3.10.0)
project(mini_shell VERSION 0.1.0 LANGUAGES C)

set(SOURCES
    src/main.c
    src/parser.c
    src/executor.c)

set(HEADERS
    include/init.h
    include/parser.h
    include/executor.h)

include_directories(include)

add_executable(mini_shell ${SOURCES})


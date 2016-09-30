cmake_minimum_required(VERSION 3.6)
project(Automata1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c ejemplo2.c)
add_executable(${SOURCE_FILES})
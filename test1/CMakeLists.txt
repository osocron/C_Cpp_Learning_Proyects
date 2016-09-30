cmake_minimum_required(VERSION 3.3)
project(test1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c)
add_executable(test1 ${SOURCE_FILES})
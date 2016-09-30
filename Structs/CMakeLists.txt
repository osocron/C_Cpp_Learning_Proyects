cmake_minimum_required(VERSION 3.3)
project(Structs)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.cpp)
add_executable(Structs ${SOURCE_FILES})
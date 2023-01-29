cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_subdirectory("source/5. Stack and Queue")

add_executable(test test.cpp)
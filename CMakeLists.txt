cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_subdirectory("source/Linked List")

add_executable(test test.cpp)
cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# add_subdirectory("source/Linked List")
# add_subdirectory("source/Hash Table")
# add_subdirectory("source/String")
add_subdirectory("source/Stack and Queue")

add_executable(test test.cpp)
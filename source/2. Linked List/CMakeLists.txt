cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 23)

add_executable(LinkedList 25-reverse-nodes-in-k-group.cpp)

target_link_libraries(LinkedList LeetCode)
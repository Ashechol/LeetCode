cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 23)

add_executable(linked-list-cycle-ii linked-list-cycle-ii_142.cpp)
add_library(libListNode ListNode.cpp)

target_link_libraries(linked-list-cycle-ii libListNode)
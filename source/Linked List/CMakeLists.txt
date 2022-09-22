cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 23)

add_library(libLinkedList SHARED LinkedList.cpp)
add_executable(design-linked-list_707 design-linked-list_707.cpp)

target_link_libraries(design-linked-list_707 libLinkedList)

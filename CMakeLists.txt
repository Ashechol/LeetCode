cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(lib)

add_subdirectory("source/1. Array")
add_subdirectory("source/2. Linked List")
add_subdirectory("source/4. String")
add_subdirectory("source/6. Tree")
# add_subdirectory("source/7. Backtracking")
# add_subdirectory("source/8. Greedy")
add_subdirectory("source/9. DP")
add_subdirectory("source/Uncategorized")
add_subdirectory("source/5. Stack and Queue")
add_executable(test test.cpp)
add_subdirectory(include)
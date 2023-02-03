cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(lib)

add_subdirectory("source/6. Tree")
add_subdirectory(include)

#add_executable(test test.cpp)
#target_link_libraries(test LeetCode)
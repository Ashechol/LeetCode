project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(tree tx.cpp)
target_link_libraries(tree LeetCode)
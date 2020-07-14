cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME tinylexer)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(tinylexer)
add_subdirectory(test_code)
add_subdirectory(example)

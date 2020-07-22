cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME example)
project(${PROJECT_NAME})

# example app
set(EXAMPLE_APP example)
add_executable(${EXAMPLE_APP} example.cpp)
target_link_libraries(${EXAMPLE_APP} lexengine)
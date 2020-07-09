cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME example)
project(${PROJECT_NAME})

# example app
set(EXAMPLE_APP example)
add_executable(${EXAMPLE_APP} main.cpp)
target_link_libraries(${EXAMPLE_APP} lexer wordid filer)
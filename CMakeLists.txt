cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME tinylexer)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(lexer)
add_subdirectory(wordid)
add_subdirectory(filer)

add_subdirectory(test)
add_subdirectory(example)
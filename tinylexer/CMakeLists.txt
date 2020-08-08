cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME tinylexer)
project(${PROJECT_NAME})

set(TINYLEXER_APP tinylex)
add_executable(${TINYLEXER_APP} tinylex.cpp)
target_link_libraries(${TINYLEXER_APP} PRIVATE lexengine)

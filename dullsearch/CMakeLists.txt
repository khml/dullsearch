cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME dullsearch)
project(${PROJECT_NAME})

set(TINYLEXER_APP dullsearch)
add_executable(${TINYLEXER_APP} dullsearch.cpp)
target_link_libraries(${TINYLEXER_APP} PRIVATE dullengine)

cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME engine)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

set(LIB_TINYLEX lexengine)
file(GLOB TINYLEX_SOURCES src/*/*.cpp)
add_library(${LIB_TINYLEX} STATIC ${TINYLEX_SOURCES})
target_link_libraries(${LIB_TINYLEX} PUBLIC stdc++fs)
target_include_directories(${LIB_TINYLEX} PUBLIC include)

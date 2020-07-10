cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME libtinylexer)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

set(LIB_TINYLEX tinylex)
file(GLOB TINYLEX_SOURCES src/*/*.cpp)
add_library(${LIB_TINYLEX} STATIC ${TINYLEX_SOURCES})
target_include_directories(${LIB_TINYLEX} PUBLIC include)

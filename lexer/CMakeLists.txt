cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME lexer)
project(${PROJECT_NAME})

# lexer lib
set(LIB_TINYLEX lexer)
file(GLOB TINYLEX_SOURCES src/*.cpp)
add_library(${LIB_TINYLEX} STATIC ${TINYLEX_SOURCES})
target_include_directories(${LIB_TINYLEX} PUBLIC include)
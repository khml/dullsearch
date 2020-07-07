cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME tinylexer)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

# tinylexer lib
set(LIB_TINYLEX tinylexer)
file(GLOB TINYLEX_SOURCES tinylexer/src/*.cpp)
add_library(${LIB_TINYLEX} STATIC ${TINYLEX_SOURCES})
target_include_directories(${LIB_TINYLEX} PUBLIC tinylexer/include)

# example app
set(EXAMPLE_APP hellolex)
add_executable(${EXAMPLE_APP} main.cpp)
target_include_directories(${EXAMPLE_APP} PUBLIC tinylexer/include)
target_link_libraries(${EXAMPLE_APP} ${LIB_TINYLEX})

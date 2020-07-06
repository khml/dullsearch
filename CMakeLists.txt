cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME tinylexer)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

include_directories(tinylexer/include)
file(GLOB SOURCES tinylexer/src/*.cpp)

add_executable(tinylexer main.cpp ${SOURCES})
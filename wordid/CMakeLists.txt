cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME wordid)
project(${PROJECT_NAME})

# wordid lib
set(LIB_WORDID wordid)
file(GLOB WORDID_SOURCES src/*.cpp)
add_library(${LIB_WORDID} STATIC ${WORDID_SOURCES})
target_include_directories(${LIB_WORDID} PUBLIC include)
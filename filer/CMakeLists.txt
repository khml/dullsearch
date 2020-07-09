cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME filer)
project(${PROJECT_NAME})

# filer lib
set(LIB_FILER filer)
file(GLOB FILER_SOURCES src/*.cpp)
add_library(${LIB_FILER} STATIC ${FILER_SOURCES})
target_include_directories(${LIB_FILER} PUBLIC include)
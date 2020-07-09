cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME tinylexer)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

# tinylexer lib
set(LIB_TINYLEX tinylexer)
file(GLOB TINYLEX_SOURCES lexer/src/*.cpp)
add_library(${LIB_TINYLEX} STATIC ${TINYLEX_SOURCES})
target_include_directories(${LIB_TINYLEX} PUBLIC lexer/include)

# wordid lib
set(LIB_WORDID wordid)
file(GLOB WORDID_SOURCES wordid/src/*.cpp)
add_library(${LIB_WORDID} STATIC ${WORDID_SOURCES})
target_include_directories(${LIB_WORDID} PUBLIC wordid/include)

# filer lib
set(LIB_FILER filer)
file(GLOB FILER_SOURCES filer/src/*.cpp)
add_library(${LIB_FILER} STATIC ${FILER_SOURCES})
target_include_directories(${LIB_FILER} PUBLIC filer/include)

# example app
set(EXAMPLE_APP hellolex)
add_executable(${EXAMPLE_APP} example/main.cpp)
target_include_directories(${EXAMPLE_APP} PUBLIC lexer/include)
target_include_directories(${EXAMPLE_APP} PUBLIC wordid/include)
target_include_directories(${EXAMPLE_APP} PUBLIC filer/include)
target_link_libraries(${EXAMPLE_APP} ${LIB_TINYLEX} ${LIB_WORDID} ${LIB_FILER})

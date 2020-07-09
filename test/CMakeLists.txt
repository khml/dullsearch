cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME test)
project(${PROJECT_NAME})

# test
set(TEST_APP testapp)
add_executable(${TEST_APP} main.cpp)
target_link_libraries(${TEST_APP} lexer wordid filer gtest gtest_main)
target_link_directories(${TEST_APP} PUBLIC ../thirdparty/googletest-1.10.0/lib)
target_include_directories(${TEST_APP} PUBLIC ../thirdparty/googletest-1.10.0/include)

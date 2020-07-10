cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME test)
project(${PROJECT_NAME})

find_package(GTest)

# test
set(TEST_APP test)
add_executable(${TEST_APP} main.cpp)
target_link_libraries(${TEST_APP} tinylex ${GTEST_BOTH_LIBRARIES})
target_include_directories(${TEST_APP} PUBLIC ${GTEST_INCLUDE_DIRS})

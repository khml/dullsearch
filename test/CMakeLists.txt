cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME test)
project(${PROJECT_NAME})

find_package(GTest)

# test
set(TEST_APP test)
add_executable(${TEST_APP} main.cpp)
target_link_libraries(${TEST_APP} tinylex ${GTEST_BOTH_LIBRARIES} gmock gmock_main)
get_filename_component(GTEST_LIB_DIR ${GTEST_LIBRARY} DIRECTORY)
target_link_directories(${TEST_APP} PUBLIC ${GTEST_LIB_DIR})
target_include_directories(${TEST_APP} PUBLIC ${GTEST_INCLUDE_DIRS})

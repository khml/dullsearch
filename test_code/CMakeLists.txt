cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME test)
project(${PROJECT_NAME})

find_package(GTest)

# test_code
set(TEST_APP test_tinylex)
add_executable(${TEST_APP} main.cpp)
target_link_libraries(${TEST_APP} lexengine ${GTEST_BOTH_LIBRARIES} gmock gmock_main pthread)
get_filename_component(GTEST_LIB_DIR ${GTEST_LIBRARY} DIRECTORY)
target_link_directories(${TEST_APP} PUBLIC ${GTEST_LIB_DIR})
target_include_directories(${TEST_APP} PUBLIC ${GTEST_INCLUDE_DIRS})

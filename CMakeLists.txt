cmake_minimum_required(VERSION 3.15)

project(unittest)

# Include Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Set compiler flags for coverage
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)
set(CTEST_COVERAGE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/coverage")

# Include directories
include_directories(link_list)

# Add your source files here if needed
# set(SOURCES link_list/unittest_LinkList.cpp)

# Create the unittest executable
add_executable(
    unittest
    link_list/unittest_LinkList.cpp
    binary_tree/unittest_binary_tree.cpp
)

# Link Google Test and your project's code
target_link_libraries(unittest PRIVATE gtest_main)

# Define a test using CTest
add_test(
    NAME unittest
    COMMAND unittest
)

# Create a custom target for generating coverage reports
add_custom_target(
    coverage
    COMMAND ctest -T Coverage
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

find_program(VALGRIND "valgrind")

if(VALGRIND)
    add_custom_target(
        memcheck
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest>
    )
endif()

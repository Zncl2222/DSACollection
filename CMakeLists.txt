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
include_directories(binary_tree)
include_directories(stack)

# Define your source files
set(LINK_LIST_TEST_SOURCES
    link_list/unittest_LinkList.cpp
)

set(BINARY_TREE_TEST_SOURCES
    binary_tree/unittest_binary_tree.cpp
)

set(LINK_STACK_TEST_SOURCES
    stack/unittest_link_stack.cpp
)

set(SQ_STACK_TEST_SOURCES
    stack/unittest_sq_stack.cpp
)

set(LINK_QUEUE_TEST_SOURCES
    queue/link_queue/unittest_link_queue.cpp
)

# Create the unittest executables
add_executable(unittest_link_list ${LINK_LIST_TEST_SOURCES})
add_executable(unittest_binary_tree ${BINARY_TREE_TEST_SOURCES})
add_executable(unittest_link_stack ${LINK_STACK_TEST_SOURCES})
add_executable(unittest_sq_stack ${SQ_STACK_TEST_SOURCES})
add_executable(unittest_link_queue ${LINK_QUEUE_TEST_SOURCES})

# Link Google Test and your project's code
target_link_libraries(unittest_link_list PRIVATE gtest_main)
target_link_libraries(unittest_binary_tree PRIVATE gtest_main)
target_link_libraries(unittest_link_stack PRIVATE gtest_main)
target_link_libraries(unittest_sq_stack PRIVATE gtest_main)
target_link_libraries(unittest_link_queue PRIVATE gtest_main)

# Define tests using CTest
add_test(NAME unittest_link_list COMMAND unittest_link_list)
add_test(NAME unittest_binary_tree COMMAND unittest_binary_tree)
add_test(NAME unittest_link_stack COMMAND unittest_link_stack)
add_test(NAME unittest_sq_stack COMMAND unittest_sq_stack)
add_test(NAME unittest_link_queue COMMAND unittest_link_queue)

# Create a custom target for generating coverage reports
add_custom_target(coverage COMMAND ctest -T Coverage WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

find_program(VALGRIND "valgrind")

if(VALGRIND)
    add_custom_target(memcheck
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_link_list>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_binary_tree>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_link_stack>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_sq_stack>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_link_queue>
    )
endif()

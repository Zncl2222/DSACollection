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
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcommon -fprofile-arcs -ftest-coverage")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)
set(CTEST_COVERAGE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/coverage")

# Include directories
add_subdirectory(link_list)
add_subdirectory(binary_tree)
add_subdirectory(stack)
add_subdirectory(queue)
add_subdirectory(sorting/c)
add_subdirectory(sorting/cpp)

# Define your source files
set(LINK_LIST_TEST_SOURCES
    link_list/c/unittest_LinkList.cpp
)

set(BINARY_TREE_TEST_SOURCES
    binary_tree/c/unittest_binary_tree.cpp
)

set(LINK_STACK_TEST_SOURCES
    stack/c/unittest_link_stack.cpp
)

set(SQ_STACK_TEST_SOURCES
    stack/c/unittest_sq_stack.cpp
)

set(LINK_QUEUE_TEST_SOURCES
    queue/c/unittest_link_queue.cpp
)

set(SQ_QUEUE_TEST_SOURCES
    queue/c/unittest_sequential_queue.cpp
)

set(BUBBLE_SORT_TEST_SOURCES
    sorting/c/bubble_sort/unittest_bubble_sort.cpp
)

set(HEAP_SORT_TEST_SOURCES
    sorting/c/heap_sort/unittest_heap_sort.cpp
)

set(QUICK_SORT_TEST_SOURCES
    sorting/c/quick_sort/unittest_quick_sort.cpp
)

set(SELECTION_SORT_TEST_SOURCES
    sorting/cpp/selection_sort/unittest_selection_sort.cpp
)

set(SHELL_SORT_TEST_SOURCES
    sorting/cpp/shell_sort/unittest_shell_sort.cpp
)

set(INSERTION_SORT_TEST_SOURCES
    sorting/cpp/insertion_sort/unittest_insertion_sort.cpp
)

set(TEST_TARGETS
    link_list
    binary_tree
    link_stack
    sq_stack
    link_queue
    sq_queue
    bubble_sort
    heap_sort
    quick_sort
    selection_sort
)

# Create the unittest executables
add_executable(unittest_link_list ${LINK_LIST_TEST_SOURCES})
add_executable(unittest_binary_tree ${BINARY_TREE_TEST_SOURCES})
add_executable(unittest_link_stack ${LINK_STACK_TEST_SOURCES})
add_executable(unittest_sq_stack ${SQ_STACK_TEST_SOURCES})
add_executable(unittest_link_queue ${LINK_QUEUE_TEST_SOURCES})
add_executable(unittest_sq_queue ${SQ_QUEUE_TEST_SOURCES})
add_executable(unittest_bubble_sort ${BUBBLE_SORT_TEST_SOURCES})
add_executable(unittest_heap_sort ${HEAP_SORT_TEST_SOURCES})
add_executable(unittest_quick_sort ${QUICK_SORT_TEST_SOURCES})
add_executable(unittest_selection_sort ${SELECTION_SORT_TEST_SOURCES})
add_executable(unittest_shell_sort ${SHELL_SORT_TEST_SOURCES})
add_executable(unittest_insertion_sort ${SHELL_SORT_TEST_SOURCES})

# Link Google Test and your project's code
foreach(TEST_TARGET ${TEST_TARGETS})
    target_link_libraries(unittest_${TEST_TARGET} PRIVATE gtest_main ${TEST_TARGET} gcov)
    add_test(NAME unittest_${TEST_TARGET} COMMAND unittest_${TEST_TARGET})
endforeach()

# Define tests using CTest (These two codes implement in header so don't need to link source file)
target_link_libraries(unittest_shell_sort PRIVATE gtest_main gcov)
target_link_libraries(unittest_insertion_sort PRIVATE gtest_main gcov)
add_test(NAME unittest_shell_sort COMMAND unittest_shell_sort)
add_test(NAME unittest_insertion_sort COMMAND unittest_insertion_sort)

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
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_sq_queue>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_bubble_sort>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_heap_sort>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_quick_sort>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_selection_sort>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_shell_sort>
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_insertion_sort>
    )
endif()

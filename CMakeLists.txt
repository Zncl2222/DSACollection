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
add_subdirectory(sorting/bubble_sort)
add_subdirectory(sorting/heap_sort)
add_subdirectory(sorting/quick_sort)
add_subdirectory(sorting/selection_sort)


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

set(SQ_QUEUE_TEST_SOURCES
    queue/sequential_queue/unittest_sequential_queue.cpp
)

set(BUBBLE_SORT_TEST_SOURCES
    sorting/bubble_sort/unittest_bubble_sort.cpp
)

set(HEAP_SORT_TEST_SOURCES
    sorting/heap_sort/unittest_heap_sort.cpp
)

set(QUICK_SORT_TEST_SOURCES
    sorting/quick_sort/unittest_quick_sort.cpp
)

set(SELECTION_SORT_TEST_SOURCES
    sorting/selection_sort/unittest_selection_sort.cpp
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

# Link Google Test and your project's code
target_link_libraries(unittest_link_list PRIVATE gtest_main link_list gcov)
target_link_libraries(unittest_binary_tree PRIVATE gtest_main binary_tree gcov)
target_link_libraries(unittest_link_stack PRIVATE gtest_main link_stack gcov)
target_link_libraries(unittest_sq_stack PRIVATE gtest_main sequential_stack gcov)
target_link_libraries(unittest_link_queue PRIVATE gtest_main link_queue gcov)
target_link_libraries(unittest_sq_queue PRIVATE gtest_main sequential_queue gcov)
target_link_libraries(unittest_bubble_sort PRIVATE gtest_main bubble_sort gcov)
target_link_libraries(unittest_heap_sort PRIVATE gtest_main heap_sort gcov)
target_link_libraries(unittest_quick_sort PRIVATE gtest_main quick_sort gcov)
target_link_libraries(unittest_selection_sort PRIVATE gtest_main selection_sort gcov)

# Define tests using CTest
add_test(NAME unittest_link_list COMMAND unittest_link_list)
add_test(NAME unittest_binary_tree COMMAND unittest_binary_tree)
add_test(NAME unittest_link_stack COMMAND unittest_link_stack)
add_test(NAME unittest_sq_stack COMMAND unittest_sq_stack)
add_test(NAME unittest_link_queue COMMAND unittest_link_queue)
add_test(NAME unittest_sq_queue COMMAND unittest_sq_queue)
add_test(NAME unittest_bubble_sort COMMAND unittest_bubble_sort)
add_test(NAME unittest_heap_sort COMMAND unittest_heap_sort)
add_test(NAME unittest_quick_sort COMMAND unittest_quick_sort)
add_test(NAME unittest_selection_sort COMMAND unittest_selection_sort)

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
    )
endif()

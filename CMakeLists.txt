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

# Please don remove the comment of "Set test targets" and "End of test targets"
# This is for shell script and batch file to generate memcheck test targets
# Set test targets
set(
    TEST_TARGETS
    link_list
    binary_tree
    link_stack
    sq_stack
    link_queue
    sq_queue
    bubble_sort
    heap_sort
    merge_sort
    quick_sort
    selection_sort
)
# End of test targets

# Link Google Test and your project's code
foreach(TEST_TARGET ${TEST_TARGETS})
    target_link_libraries(unittest_${TEST_TARGET} PRIVATE gtest_main ${TEST_TARGET} gcov)
    add_test(NAME unittest_${TEST_TARGET} COMMAND unittest_${TEST_TARGET})
endforeach()


# Create a custom target for generating coverage reports
add_custom_target(coverage COMMAND ctest -T Coverage WORKING_DIRECTORY ${CMAKE_BINARY_DIR})


function(add_memcheck_target TEST_TARGET)
    add_custom_target(memcheck_${TEST_TARGET}
        COMMAND ${VALGRIND}
        --tool=memcheck
        --leak-check=full
        --track-origins=yes
        --show-reachable=yes
        --error-exitcode=1
        $<TARGET_FILE:unittest_${TEST_TARGET}>
    )
endfunction()

find_program(VALGRIND "valgrind")
if(VALGRIND)
    # Call the function for each test target
    foreach(TEST_TARGET ${TEST_TARGETS})
        add_memcheck_target(${TEST_TARGET})
    endforeach()
endif()

# SelectionSort
project(selection_sort CXX)
set(
    SELECTION_SORT_TEST_SOURCES
    selection_sort/unittest_selection_sort.cpp
)
add_executable(unittest_selection_sort ${SELECTION_SORT_TEST_SOURCES})
add_library(selection_sort selection_sort/selection_sort.cpp)

# shell_sort and insertion_sort
include_directories(shell_sort)
include_directories(insertion_sort)

set(
    SHELL_SORT_TEST_SOURCES
    shell_sort/unittest_shell_sort.cpp
)

set(
    INSERTION_SORT_TEST_SOURCES
    insertion_sort/unittest_insertion_sort.cpp
)

add_executable(unittest_shell_sort ${SHELL_SORT_TEST_SOURCES})
add_executable(unittest_insertion_sort ${INSERTION_SORT_TEST_SOURCES})

# Define tests using CTest (These two codes implement in header so don't need to link source file)
target_link_libraries(unittest_shell_sort PRIVATE gtest_main gcov)
target_link_libraries(unittest_insertion_sort PRIVATE gtest_main gcov)
add_test(NAME unittest_shell_sort COMMAND unittest_shell_sort)
add_test(NAME unittest_insertion_sort COMMAND unittest_insertion_sort)

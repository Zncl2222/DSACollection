project(selection_sort CXX)
add_library(selection_sort selection_sort/selection_sort.cpp)

# shell_sort and insertion_sort
include_directories(shell_sort)
include_directories(insertion_sort)

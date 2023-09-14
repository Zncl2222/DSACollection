project(selection_sort CXX)
add_library(selection_sort selection_sort/selection_sort.cpp)

project(quick_sort)
add_library(quick_sort quick_sort/quick_sort.c)

project(heap_sort)
add_library(heap_sort heap_sort/heap_sort.c)

project(bubble_sort)
add_library(bubble_sort bubble_sort/bubble_sort.c)

# shell_sort and insertion_sort
include_directories(shell_sort)
include_directories(insertion_sort)

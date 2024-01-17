# QuickSort
project(quick_sort)
set(
    QUICK_SORT_TEST_SOURCES
    quick_sort/unittest_quick_sort.cpp
)
add_executable(unittest_quick_sort ${QUICK_SORT_TEST_SOURCES})
add_library(quick_sort quick_sort/quick_sort.c)


# HeapSort
project(heap_sort)
set(
    HEAP_SORT_TEST_SOURCES
    heap_sort/unittest_heap_sort.cpp
)
add_executable(unittest_heap_sort ${HEAP_SORT_TEST_SOURCES})
add_library(heap_sort heap_sort/heap_sort.c)

# BubbleSort
project(bubble_sort)
set(
    BUBBLE_SORT_TEST_SOURCES
    bubble_sort/unittest_bubble_sort.cpp
)
add_executable(unittest_bubble_sort ${BUBBLE_SORT_TEST_SOURCES})
add_library(bubble_sort bubble_sort/bubble_sort.c)


# MergeSort
project(merge_sort)
set(
    MERGE_SORT_TEST_SOURCES
    merge_sort/unittest_merge_sort.cpp
)
add_executable(unittest_merge_sort ${MERGE_SORT_TEST_SOURCES})
add_library(merge_sort merge_sort/merge_sort.c)

// Copyright 2022 Zncl2222
#include <gtest/gtest.h>
extern "C" {
#include "heap_sort.h"
}

TEST(HeapSortTest, SortsArrayCorrectly) {
    int arr[] = {5, 2, 9, 1, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, arr_size);
    PrintArray(arr, arr_size);
    for (int i = 1; i < arr_size; i++) {
        EXPECT_LE(arr[i - 1], arr[i]);
    }
}

TEST(HeapSortTest, SortsEmptyArray) {
    int arr[] = {};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, arr_size);
    PrintArray(arr, arr_size);
    ASSERT_EQ(arr_size, 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

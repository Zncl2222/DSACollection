// Copyright 2024 Zncl2222
#include <gtest/gtest.h>
extern "C" {
#include "merge_sort.h"
}

TEST(MergeSortTest, SortsArrayCorrectly) {
    int arr[] = {5, 2, 9, 1, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, arr_size - 1);
    print_array(arr, arr_size);
    for (int i = 1; i < arr_size; i++) {
        EXPECT_LE(arr[i - 1], arr[i]);
    }
}

TEST(MergeSortTest, SortsEmptyArray) {
    int arr[] = {};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, arr_size - 1);
    print_array(arr, arr_size);
    ASSERT_EQ(arr_size, 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

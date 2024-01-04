// Copyright 2023 Zncl2222
#include <gtest/gtest.h>
#include "insertion_sort.hpp"

// Test case to check if the array is sorted in ascending order
TEST(InsertionSortTest, AscendingOrder) {
    int arr[] = {5, 2, 9, 1, 5};
    int expected[] = {1, 2, 5, 5, 9};
    int len = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, len);

    for (int i = 0; i < len; i++) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

// Test case to check if the array is sorted in ascending order
TEST(InsertionSortTest, AscendingOrder2) {
    int arr[] = {8, 4, 2, 7, 1};
    int expected[] = {1, 2, 4, 7, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, len);

    for (int i = 0; i < len; i++) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

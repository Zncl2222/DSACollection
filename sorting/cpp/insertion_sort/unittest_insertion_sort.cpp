// Copyright 2023 Zncl2222
#include <gtest/gtest.h>
#include "insertion_sort.hpp"

// Test case to check if the array is sorted in ascending order
TEST(InsertionSortTest, AscendingOrder) {
    vector<int> arr{1, 2, 5, 5, 9};
    int expected[] = {1, 2, 5, 5, 9};

    insertion_sort<int>(arr);

    for (int i = 0; i < arr.size(); i++) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

// Test case to check if the array is sorted in ascending order
TEST(InsertionSortTest, AscendingOrder2) {
    vector<int> arr{1, 2, 4, 7, 8};
    int expected[] = {1, 2, 4, 7, 8};

    insertion_sort<int>(arr);

    for (int i = 0; i < arr.size(); i++) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

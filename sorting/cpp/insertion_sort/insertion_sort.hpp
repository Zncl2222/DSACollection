// Copyright 2023 Zncl2222
#ifndef SORTING_CPP_INSERTION_SORT_INSERTION_SORT_HPP_
#define SORTING_CPP_INSERTION_SORT_INSERTION_SORT_HPP_

#include <cstdio>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

template <typename T>
void insertion_sort(std::vector<T>& arr) {  // NOLINT
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#endif  // SORTING_CPP_INSERTION_SORT_INSERTION_SORT_HPP_

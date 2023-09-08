// Copyright 2023 Zncl2222
#ifndef SORTING_SHELL_SORT_SHELL_SORT_HPP_
#define SORTING_SHELL_SORT_SHELL_SORT_HPP_

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

template <class T>
void shell_sort(T data[], int len) {
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; i++) {
            T value = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > value; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = value;
        }
    }
}

#endif  // SORTING_SHELL_SORT_SHELL_SORT_HPP_

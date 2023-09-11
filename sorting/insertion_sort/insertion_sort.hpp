// Copyright 2023 Zncl2222
#ifndef SORTING_INSERTION_SORT_INSERTION_SORT_HPP_
#define SORTING_INSERTION_SORT_INSERTION_SORT_HPP_

#include <cstdio>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

template <typename T>
void insertion_sort(T data[], int len) {
    for (int i = 1; i < len; i++) {
        T tmp = data[i];
        int j = i - 1;

        while (tmp < data[j] && j >= 0) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = tmp;
    }
}

template <typename T>
void print_array(T data[], int len) {
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

#endif  // SORTING_INSERTION_SORT_INSERTION_SORT_HPP_

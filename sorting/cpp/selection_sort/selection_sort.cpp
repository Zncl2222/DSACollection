// Copyright 2023 Zncl2222
#include <iostream>
#include <vector>
#include "selection_sort.hpp"

using std::cout;
using std::vector;
using std::endl;

template <typename T>
void array_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
template void array_swap<int>(int&, int&);

template <typename T>
void selection_sort(T data[], int len) {
    int min_index;
    for (int i = 0; i < len - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < len; j++) {
            if (data[j] < data[min_index]) {
                min_index = j;
            }
        }
        array_swap(data[i], data[min_index]);
    }
}
template void selection_sort<int>(int[], int);

template <typename T>
void print_array(T data[], int len) {
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
template void print_array<int>(int[], int);

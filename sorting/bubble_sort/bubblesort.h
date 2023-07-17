// Copyright 2022 Zncl2222
#ifndef SORTING_BUBBLE_SORT_BUBBLESORT_H_
#define SORTING_BUBBLE_SORT_BUBBLESORT_H_

#include <stdio.h>

typedef int datatype;

void swap(datatype* a, datatype* b) {
    datatype temp = *a;
    *a = *b;
    *b = temp;
}

void b_sort(datatype* array, int array_size) {
    datatype temp;

    for (int i = 0; i < array_size; i++) {
        for (int j = array_size; j >= i; j--) {
            if (array[j] > array[j + 1]) swap(&array[j], &array[j + 1]);  // NOLINT
        }
    }
}

void PrintArray(int* array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#endif  // SORTING_BUBBLE_SORT_BUBBLESORT_H_

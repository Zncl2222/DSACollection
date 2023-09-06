// Copyright 2022 Zncl2222
#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* array, int front, int end) {
    int pivotkey = array[front];

    while (front < end) {
        while (front < end && array[end] >= pivotkey) {
            end--;
        }
        swap(&array[end], &array[front]);

        while (front < end && array[front] <= pivotkey) {
            front++;
        }
        swap(&array[end], &array[front]);  //  NOLINT
    }

    return front;
}

void quicksort(int* array, int front, int end) {
    int pivot;

    if (front < end) {
        pivot = partition(array, front, end);
        quicksort(array, front, pivot - 1);
        quicksort(array, pivot + 1, end);
    }
}

void print_array(int* array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

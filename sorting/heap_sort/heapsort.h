// Copyright 2022 Zncl2222
#ifndef SORTING_HEAP_SORT_HEAPSORT_H_
#define SORTING_HEAP_SORT_HEAPSORT_H_

#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapAdjust(int* L, int curridx, int L_size) {
    int temp, i;

    temp = L[curridx];

    for (i = 2 * curridx + 1; i <= L_size; i = i * 2 + 1) {
        if (i < L_size && L[i] < L[i + 1]) ++i;

        if (temp > L[i]) break;
        L[curridx] = L[i];
        curridx = i;
    }

    L[curridx] = temp;
}

void HeapSort(int* L, int L_size) {
    for (int i = L_size / 2 - 1; i >= 0; i--) {
        HeapAdjust(L, i, L_size);
    }

    for (int i = L_size - 1; i > 0; i--) {
        Swap(&L[0], &L[i]);
        HeapAdjust(L, 0, i - 1);
    }
}

void PrintArray(int* L, int L_size) {
    for (int i = 0; i < L_size; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
}

#endif  // SORTING_HEAP_SORT_HEAPSORT_H_

// Copyright 2022 Zncl2222
#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapAdjust(int* L, int curridx, int L_size) {
    int temp, i;

    temp = L[curridx];

    for (i = 2 * curridx + 1; i < L_size; i = 2 * i + 1) {
        if (i + 1 < L_size && L[i] < L[i + 1]) {
            ++i;
        }

        if (temp > L[i]) {
            break;
        }
        L[curridx] = L[i];
        curridx = i;
    }

    L[curridx] = temp;
}

void HeapSort(int* L, int L_size) {
    if (L_size <= 1) {
        return;
    }

    for (int i = L_size / 2 - 1; i >= 0; i--) {
        HeapAdjust(L, i, L_size);
    }

    for (int i = L_size - 1; i > 0; i--) {
        Swap(&L[0], &L[i]);
        HeapAdjust(L, 0, i);
    }
}

void PrintArray(int* L, int L_size) {
    for (int i = 0; i < L_size; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
}

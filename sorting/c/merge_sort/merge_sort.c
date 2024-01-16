// Copyright 2024 Zncl222
#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

void merge(int* L, int left, int mid, int right) {
    int temp_size = right - left + 1;
    int *temp = (int*)malloc(sizeof(int) * temp_size);

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (L[i] <= L[j]) {
            temp[k++] = L[i++];
        } else {
            temp[k++] = L[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = L[i++];
    }

    while (j <= right) {
        temp[k++] = L[j++];
    }

    for (k = 0; k < temp_size; ++k) {
        L[left + k] = temp[k];
    }
    free(temp);
}

void merge_sort(int* L, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(L, left, mid);
        merge_sort(L, mid + 1, right);
        merge(L, left, mid, right);
    }
}

void print_array(int* L, int L_size) {
    for (int i = 0; i < L_size; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
}

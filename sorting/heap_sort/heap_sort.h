// Copyright 2022 Zncl2222
#ifndef SORTING_HEAP_SORT_HEAP_SORT_H_
#define SORTING_HEAP_SORT_HEAP_SORT_H_

#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b);

void HeapAdjust(int* L, int curridx, int L_size);

void HeapSort(int* L, int L_size);

void PrintArray(int* L, int L_size);

#endif  // SORTING_HEAP_SORT_HEAP_SORT_H_

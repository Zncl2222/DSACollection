// Copyright 2022 Zncl2222
#ifndef SORTING_QUICK_SORT_QUICK_SORT_H_
#define SORTING_QUICK_SORT_QUICK_SORT_H_

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int partition(int* array, int front, int end);

void quicksort(int* array, int front, int end);

void print_array(int* array, int array_size);

#endif  // SORTING_QUICK_SORT_QUICK_SORT_H_

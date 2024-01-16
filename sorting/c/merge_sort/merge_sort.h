// Copyright 2024 Zncl2222
#ifndef SORTING_C_MERGE_SORT_MERGE_SORT_H_
#define SORTING_C_MERGE_SORT_MERGE_SORT_H_

#include <stdio.h>
#include <stdlib.h>

void merge(int* L, int left, int mid, int right);

void merge_sort(int* L, int left, int right);

void print_array(int* L, int L_size);

#endif  // SORTING_C_MERGE_SORT_MERGE_SORT_H_

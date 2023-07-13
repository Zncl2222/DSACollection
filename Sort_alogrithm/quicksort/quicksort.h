#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int* array, int front, int end) {
    int pivotkey = array[front];

    while (front < end) {
        while (front < end && array[end] >= pivotkey) {
            end--;
        }
        swap(&array[end], &array[front]);

        while (front < end && array[front] <= pivotkey) {
            front++;
        }
        swap(&array[end], &array[front]);
    }

    return front;
}

void quicksort(int* array, int front, int end) {
    int pivot;

    if (front < end) {
        pivot = Partition(array, front, end);
        quicksort(array, front, pivot - 1);
        quicksort(array, pivot + 1, end);
    }
}

void PrintArray(int* array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int test(int a, int b) {
    printf("heheh");
    return a + b;
}
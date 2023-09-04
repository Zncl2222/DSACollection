// Copyright 2022 Zncl2222

#include <stdio.h>
#include <stdlib.h>

#include "Sequential_queue.h"


int main() {
    SqQueue q;

    SqQueue_Init(&q);

    printf("\nQueue push\n");
    for (int i = 0; i < 6; i++) {
        SqQueue_Push(&q, i * 2);
        SqQueue_Getfront(&q);
        SqQueue_Getrear(&q);
    }

    SqQueue_Traverse(&q);
    SqQueue_Getfront(&q);
    SqQueue_Getrear(&q);

    printf("\nQueue pop\n");
    for (int i = 0; i < 3; i++) {
        SqQueue_Pop(&q);
    }
    SqQueue_Traverse(&q);
    SqQueue_Getfront(&q);
    SqQueue_Getrear(&q);

    printf("\nQueue pop\n");
    for (int i = 0; i < 3; i++) {
        SqQueue_Pop(&q);
    }

    SqQueue_Traverse(&q);
    SqQueue_Getfront(&q);
    SqQueue_Getrear(&q);
    SqQueue_Length(&q);

    printf("\nQueue push\n");
    for (int i = 0; i < 5; i++) {
        SqQueue_Push(&q, i * 15);
    }
    SqQueue_Traverse(&q);
    SqQueue_Getfront(&q);
    SqQueue_Getrear(&q);

    SqQueue_Length(&q);

    system("Pause");
    return 0;
}

// Copyright 2022 Zncl2222
#ifndef QUEUE_SEQUENTIAL_QUEUE_SEQUENTIAL_QUEUE_H_
#define QUEUE_SEQUENTIAL_QUEUE_SEQUENTIAL_QUEUE_H_

#include <stdio.h>

#define MAX_SIZE 20
typedef int datatype;

typedef struct queue {
    datatype data[MAX_SIZE];
    int front;
    int rear;
} SqQueue;

void SqQueue_Init(SqQueue* q) {
    printf("(SqQueue_Init) SqQueue init success !\n");
    q->front = 0;
    q->rear = 0;
}

int SqQueue_Length(SqQueue* q) {
    return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}

void SqQueue_Push(SqQueue* q, datatype val) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("(SqQueue_Push) ERROR: Queue is full\n");
        return;
    }

    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

void SqQueue_Pop(SqQueue* q) {
    if (q->front == q->rear) {
        printf("(SqQueue_Pop) ERROR: Queue is empty\n");
        return;
    }
    q->front = (q->front + 1) % MAX_SIZE;
}

datatype SqQueue_Getfront(SqQueue* q) {
    if (q->front == q->rear) {
        printf("(SqQueue_Getfront) ERROR: Queue is empty\n");
        return -9999;
    }
    printf("(SqQueue_Getfront) Front ptr value %d\n", q->data[q->front]);
    return q->data[q->front];
}

datatype SqQueue_Getrear(SqQueue* q) {
    if (q->front == q->rear) {
        printf("(SqQueue_Getrear)ERROR: Queue is empty\n");
        return -9999;
    }
    printf("(SqQueue_Getrear) Rear value (Last input value) = %d\n",
           q->data[q->rear - 1]);
    return q->data[q->rear - 1];
}

void SqQueue_Traverse(SqQueue* q) {
    if (q->front == q->rear) {
        printf("(SqQueue_Traverse) ERROR: Queue is empty\n");
        return;
    }
    int len = SqQueue_Length(q);

    int start = (q->front > q->rear ? q->rear : q->front);
    int end = (q->front < q->rear ? q->rear : q->front);

    printf("\nSqQueue :\n");
    for (int i = start; i < end; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n\n");
}

#endif  // QUEUE_SEQUENTIAL_QUEUE_SEQUENTIAL_QUEUE_H_

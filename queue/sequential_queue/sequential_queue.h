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

void SqQueue_Init(SqQueue* q);

int SqQueue_Length(SqQueue* q);

void SqQueue_Push(SqQueue* q, datatype val);

void SqQueue_Pop(SqQueue* q);

datatype SqQueue_Getfront(SqQueue* q);

datatype SqQueue_Getrear(SqQueue* q);

void SqQueue_Traverse(SqQueue* q);

#endif  // QUEUE_SEQUENTIAL_QUEUE_SEQUENTIAL_QUEUE_H_

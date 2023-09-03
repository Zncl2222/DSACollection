// Copyright 2022 Zncl2222
#ifndef QUEUE_LINK_QUEUE_LINK_QUEUE_H_
#define QUEUE_LINK_QUEUE_LINK_QUEUE_H_

#include <stdio.h>

typedef int datatype;

typedef struct QueueNode {
    datatype data;
    struct QueueNode* next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
} LinkQueue;

void lk_queue_init(LinkQueue* q);

void lk_queue_push(LinkQueue* q, datatype val);

void lk_queue_pop(LinkQueue* q);

void lk_queue_destroy(LinkQueue* q);

datatype lk_queue_get_front(LinkQueue* q);

datatype lk_queue_get_rear(LinkQueue* q);

int lk_queue_size(LinkQueue* q);

void lk_queue_traverse(LinkQueue* q);

#endif  // QUEUE_LINK_QUEUE_LINK_QUEUE_H_

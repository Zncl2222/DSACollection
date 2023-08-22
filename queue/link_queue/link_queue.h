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

void lk_queue_init(LinkQueue* q) {
    printf("LkQueue init success\n");
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
    q->front->next = NULL;
}

void lk_queue_push(LinkQueue* q, datatype val) {
    QueuePtr next_node = (QueuePtr)malloc(sizeof(QNode));

    if (!next_node) return;

    next_node->data = val;
    next_node->next = NULL;

    q->rear->next = next_node;
    q->rear = next_node;
}

void lk_queue_pop(LinkQueue* q) {
    QueuePtr temp;

    if (q->front == q->rear) {
        printf("(lk_queue_pop) ERROR: Queue is empty\n");
        return;
    }

    temp = q->front->next;

    q->front->next = temp->next;

    if (q->rear == temp) q->rear = q->front;

    free(temp);
}

void lk_queue_destroy(LinkQueue* q) {
    while (q->front != q->rear) {
        lk_queue_pop(q);
    }
    free(q->front);
}

datatype lk_queue_get_front(LinkQueue* q) {
    if (q->front == q->rear) {
        printf("(lk_queue_get_front) ERROR: Queue is empty\n");
        return -9999;
    }
    printf("(lk_queue_get_front) Front ptr value %d\n", q->front->next->data);
    return q->front->next->data;
}

datatype lk_queue_get_rear(LinkQueue* q) {
    if (q->front == q->rear) {
        printf("(lk_queue_get_rear) ERROR: Queue is empty\n");
        return -9999;
    }
    printf("(lk_queue_get_rear) Rear ptr value %d\n", q->rear->data);
    return q->rear->data;
}

int lk_queue_size(LinkQueue* q) {
    QueuePtr temp = q->front;
    int count = 0;

    while (q->rear != temp) {
        temp = temp->next;
        count++;
    }
    printf("(lk_queue_size) Queue size = %d\n", count);
    return count;
}

void lk_queue_traverse(LinkQueue* q) {
    if (q->rear == q->front) {
        printf("(lk_queue_traverse) ERROR: Queue is empty\n");
        return;
    }
    QueuePtr temp;
    temp = q->front->next;
    printf("\nLkQueue :\n");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

#endif  // QUEUE_LINK_QUEUE_LINK_QUEUE_H_

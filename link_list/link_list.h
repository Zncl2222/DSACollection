// Copyright 2022 Zncl2222
#ifndef LINK_LIST_LINK_LIST_H_
#define LINK_LIST_LINK_LIST_H_

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int datatype;

struct LinkList {
    datatype val;
    struct LinkList *next;
} LinkNode;

void CreateLinkList(struct LinkList **L, int L_size, datatype init_value,
                    bool random_value) {
    struct LinkList *temp, *rear;
    srand(time(0));

    *L = (struct LinkList *)malloc(sizeof(LinkNode));
    rear = *L;
    for (int i = 0; i < L_size + 1; i++) {
        temp = (struct LinkList *)malloc(sizeof(LinkNode));

        if (random_value == true)
            temp->val = rand() % 10 + 1; // NOLINT
        else
            temp->val = init_value;

        rear->next = temp;
        rear = temp;
    }

    rear->next = NULL;
}

void DeleteLinkList(struct LinkList **L) {
    struct LinkList *a, *b;
    a = *L;

    while (a != NULL) {
        b = a->next;
        free(a);
        a = b;
    }
    *L = NULL;
}

void InsertLinkNode(struct LinkList **L, int target_idx,
                    datatype target_value) {
    struct LinkList *a, *b;
    int curr_idx = 1;

    a = *L;

    while (a != NULL && curr_idx < target_idx + 1) {
        a = a->next;
        curr_idx++;
    }

    if (a == NULL || curr_idx > target_idx + 1) {
        printf("ERROR: Out of index\n");
        return;
    } else {
        b = (struct LinkList *)malloc(sizeof(LinkNode));
        b->val = target_value;
        b->next = a->next;
        a->next = b;
    }
}

void DeleteLinkNode(struct LinkList **L, int target_idx) {
    struct LinkList *a, *b;
    int curr_idx = 1;

    a = *L;

    while (a->next != NULL && curr_idx < target_idx + 1) {
        a = a->next;
        curr_idx++;
    }

    if (a->next == NULL || curr_idx > target_idx + 1) {
        printf("ERROR: Target is not exist\n");
    } else {
        b = a->next;
        a->next = b->next;
        free(b);
    }
}

int Length(struct LinkList **L) {
    struct LinkList *temp;
    int count = 0;

    temp = *L;

    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    return count;
}

datatype Get_ElementValue(struct LinkList **L, datatype target_idx) {
    struct LinkList *temp;
    int target_value;

    temp = *L;

    for (int i = 0; i < target_idx; i++) {
        temp = temp->next;
    }

    target_value = temp->val;

    return target_value;
}

datatype Get_Elementindex(struct LinkList **L, datatype target_value) {
    struct LinkList *temp;
    int target_idx = 0;

    temp = (*L)->next;

    while (temp != NULL) {
        if (temp->val == target_value) {
            return target_idx;
        }
        temp = temp->next;
        target_idx++;
    }

    return -1;
}

void Traverse(struct LinkList **L) {
    struct LinkList *temp;
    int Len;
    temp = (*L)->next;

    Len = Length(L);

    printf("DataValue=\n");
    for (int i = 0; i < Len; i++) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

#endif  // LINK_LIST_LINK_LIST_H_

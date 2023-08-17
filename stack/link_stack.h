// Copyright 2022 Zncl2222
#ifndef STACK_LINK_STACK_H_
#define STACK_LINK_STACK_H_

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct StackNode {
    datatype val;
    struct StackNode* next;
} StackNode, *LinkStack_ptr;

typedef struct {
    LinkStack_ptr top;
    int count;
} LinkStack;

void create_stack_random(LinkStack* S, int L_size) {
    S->count = 0;

    for (int i = 0; i < L_size; i++) {
        LinkStack_ptr s = (LinkStack_ptr)malloc(sizeof(StackNode));
        s->val = rand() % 100 + 1;  // NOLINT
        s->next = S->top;
        S->top = s;
        S->count++;
    }
}

bool is_empty(LinkStack* S) {
    if (S->top == NULL)
        return true;
    else
        return false;
}


void stack_pop(LinkStack* S) {
    if (is_empty(S))
        return;

    LinkStack_ptr temp = S->top;
    S->top = S->top->next;
    free(temp);
    S->count--;
}


void delete_stack(LinkStack* S) {
    while (!is_empty(S)) {
        stack_pop(S);
    }
    free(S);
}

datatype get_top(LinkStack* S) {
    if (S->top == NULL) {
        return -1;
    }
    return S->top->val;
}

void stack_push(LinkStack* S, datatype value) {
    LinkStack_ptr s = (LinkStack_ptr)malloc(sizeof(StackNode));
    s->val = value;
    s->next = S->top;
    S->top = s;
    S->count++;
}

int stack_length(LinkStack* S) { return S->count; }

void stack_traverse(LinkStack* S) {
    if (is_empty(S)) {
        printf("Stack is empty.\n");
        return;
    }

    LinkStack_ptr temp = S->top;
    datatype* temp_array = (datatype*)malloc(S->count * sizeof(datatype));

    for (int i = 0; i < S->count; i++) {
        temp_array[i] = temp->val;
        temp = temp->next;
    }

    for (int i = S->count - 1; i >= 0; i--) {
        printf("%d ", temp_array[i]);
    }

    free(temp_array);
    printf("\nStack number = %d\n", S->count);
}

#endif  // STACK_LINK_STACK_H_

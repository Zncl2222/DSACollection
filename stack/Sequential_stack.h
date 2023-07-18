// Copyright 2022 Zncl2222
#ifndef STACK_SEQUENTIAL_STACK_H_
#define STACK_SEQUENTIAL_STACK_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef int datatype;

struct Stack {
    datatype data[MAX_SIZE];
    datatype top;
} Stack;

void CreateStack_Random(struct Stack *S) {
    for (int i = 0; i < MAX_SIZE; i++) {
        S->data[i] = rand() % 100 + 1;  // NOLINT
    }
    S->top = MAX_SIZE - 1;
}

void InitStack(struct Stack *S) { S->top = -1; }

bool IsEmpty(struct Stack *S) {
    if (S->top == -1)
        return true;
    else
        return false;
}

datatype GetTop(struct Stack *S) { return S->top; }

void StackPush(struct Stack *S, datatype value) {
    if (S->top == MAX_SIZE - 1) {
        printf("ERROR: Stack is full\n");
    } else {
        S->top++;
        S->data[S->top] = value;
    }
}

void StackPop(struct Stack *S) {
    if (S->top == -1) {
        printf("ERROR\n");
    } else {
        S->top--;
    }
}

int StackLength(struct Stack *S) { return S->top; }

void StackTarvarse(struct Stack *S) {
    if (S->top == -1) {
        printf("Stack is Empty\n");
    } else {
        for (int i = 0; i < S->top; i++) {
            printf("%d ", S->data[i]);
        }
        printf("\nThe idx of top is : %d\n", S->top);
    }
}

#endif  // STACK_SEQUENTIAL_STACK_H_

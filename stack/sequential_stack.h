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

void create_stack_random(struct Stack *S);

void init_stack(struct Stack *S);

bool is_empty(struct Stack *S);

datatype get_top(struct Stack *S);

void stack_push(struct Stack *S, datatype value);

void stack_pop(struct Stack *S);

int stack_length(struct Stack *S);

void stack_traverse(struct Stack *S);

#endif  // STACK_SEQUENTIAL_STACK_H_

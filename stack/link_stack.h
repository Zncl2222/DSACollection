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

void create_stack_random(LinkStack* S, int L_size);

bool is_empty(LinkStack* S);

void stack_pop(LinkStack* S);

void delete_stack(LinkStack* S);

datatype get_top(LinkStack* S);

void stack_push(LinkStack* S, datatype value);

int stack_length(LinkStack* S);

void stack_traverse(LinkStack* S);

#endif  // STACK_LINK_STACK_H_

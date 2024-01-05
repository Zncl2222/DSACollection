// Copyright 2022 Zncl2222
#ifndef LINK_LIST_C_LINK_LIST_H_
#define LINK_LIST_C_LINK_LIST_H_

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef int datatype;

struct LinkList {
    datatype val;
    struct LinkList *next;
} LinkNode;

void create_link_list(struct LinkList **L, int L_size, datatype init_value,
                    bool random_value);

void delete_link_list(struct LinkList **L);

void insert_link_node(struct LinkList **L, int target_idx,
                    datatype target_value);

void delete_link_node(struct LinkList **L, int target_idx);

int link_list_length(struct LinkList **L);

datatype get_element_val(struct LinkList **L, datatype target_idx);

datatype get_element_idx(struct LinkList **L, datatype target_value);

void traverse(struct LinkList **L);

#endif  // LINK_LIST_C_LINK_LIST_H_

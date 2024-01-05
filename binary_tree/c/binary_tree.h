// Copyright 2022 Zncl2222
#ifndef BINARY_TREE_C_BINARY_TREE_H_
#define BINARY_TREE_C_BINARY_TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

struct TreeNode {
    datatype val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_binary_tree_recursive(datatype arr[], int idx, int size);

struct TreeNode* create_binary_tree(datatype arr[], int size);

void free_binary_tree(struct TreeNode* root);

void preordertraverse(struct TreeNode* root);

void inordertraverse(struct TreeNode* root);

void postordertraverse(struct TreeNode* root);

#endif  // BINARY_TREE_C_BINARY_TREE_H_

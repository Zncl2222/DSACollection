// Copyright 2022 Zncl2222
#ifndef BINARY_TREE_BINARY_TREE_H_
#define BINARY_TREE_BINARY_TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

struct TreeNode {
    datatype val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_binary_tree_recursive(datatype arr[], int idx, int size) {
    if (idx >= size || arr[idx] == -1) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[idx];
    root->left = create_binary_tree_recursive(arr, 2 * idx + 1, size);
    root->right = create_binary_tree_recursive(arr, 2 * idx + 2, size);

    return root;
}

struct TreeNode* create_binary_tree(datatype arr[], int size) {
    return create_binary_tree_recursive(arr, 0, size);
}

void free_binary_tree(struct TreeNode* root) {
    if (root == NULL) return;

    free_binary_tree(root->left);
    free_binary_tree(root->right);
    free(root);
}

void preordertraverse(struct TreeNode* root) {
    if (root == NULL) return;

    printf("Value = %d\n", root->val);
    preordertraverse(root->left);
    preordertraverse(root->right);
}

void inordertraverse(struct TreeNode* root) {
    if (root == NULL) return;

    inordertraverse(root->left);
    printf("Value = %d\n", root->val);
    inordertraverse(root->right);
}

void postordertraverse(struct TreeNode* root) {
    if (root == NULL) return;

    postordertraverse(root->left);
    postordertraverse(root->right);
    printf("Value = %d\n", root->val);
}

#endif  // BINARY_TREE_BINARY_TREE_H_

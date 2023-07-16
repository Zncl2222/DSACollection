#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef int (*func)(int);
int idx = 0;

struct TreeNode {
    datatype val;
    struct TreeNode* left;
    struct TreeNode* right;

} TreeNode;

struct TreeNode* create_binary_tree() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int val;
    printf("Input the value (-1 = NULL):\n");
    scanf(" %d", &val);

    if (val == -1) {
        root = NULL;
    } else {
        root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

        root->val = val;
        printf("Valueaa = %d\n", root->val);
        root->left = create_binary_tree();
        root->right = create_binary_tree();
    }

    return root;
}

void preordertraverse(struct TreeNode* root) {
    if (root == NULL) return;

    printf("Value = %d\n", root->val);
    preordertraverse(root->left);
    preordertraverse(root->right);
}

void inordertraverse(struct TreeNode* root) {
    if (root == NULL) return;

    preordertraverse(root->left);
    printf("Value = %d\n", root->val);
    preordertraverse(root->right);
}

void postordertraverse(struct TreeNode* root) {
    if (root == NULL) return;

    preordertraverse(root->left);
    preordertraverse(root->right);
    printf("Value = %d\n", root->val);
}
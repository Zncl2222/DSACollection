# include <stdio.h>
# include <stdlib.h>
# include "BinaryTree.h"


int main(){

    struct TreeNode* root;
  

    int array[10] = {0,1,5,INT_MIN,5,1,INT_MIN,2,6,INT_MIN};
    root = create_binary_tree();
    printf("ROOt %d\n",root->val);
    inordertraverse(root);

    system("Pause");

    return 0;
}
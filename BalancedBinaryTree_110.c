#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

int height(struct TreeNode* n){ 
    if(n == NULL){ return 0; }

    int left_height = height(n->left);
    if(left_height == -1){ return -1; }

    int right_height = height(n->right);
    if(right_height == -1){ return -1; }

    if(abs(left_height - right_height) > 1){ return -1; }

    return 1 + (left_height > right_height ? left_height : right_height);
}

bool isBalanced(struct TreeNode* root){ return height(root) != -1; }

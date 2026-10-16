# include <stdio.h>
# include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *insert(TreeNode *root, int value){
    if(root == NULL){ 
        TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));
        new_node->val = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if(value < root->val){ root->left = insert(root->left, value); }
    else if(value > root->val){ root->right = insert(root->right, value); }

    return root;
}

void deleteTree(TreeNode *root){
    if(root == NULL){ return; }

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}
 
// Note: The returned array must be malloced, assume caller calls free().
int* inorderTraversal(TreeNode *root, int *returnSize){
    *returnSize = 0;
    if(root == NULL){ return NULL; }

    int *result = (int*)malloc(100 * sizeof(int));

    TreeNode *stack[100];
    int top = -1;

    TreeNode *current = root;

    while(current != NULL || top != -1){
        while(current != NULL){ stack[++top] = current; current = current->left; }
        current = stack[top--];
        result[(*returnSize)++] = current->val;
        current = current->right;
    }
    return result;
}

int main(){
    TreeNode *root = NULL;
    
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    int size = 0;
    int *arr = inorderTraversal(root, &size);

    printf("Recorrido Inorder: ");
    for (int i = 0; i < size; i++){ printf("%d ", arr[i]); }
    printf("\n");

    free(arr);
    deleteTree(root);


    return 0;
}

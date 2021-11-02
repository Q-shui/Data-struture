#include <malloc.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void arr_push(struct TreeNode* root, int* arr, int* returnSize)
{
    if (root == NULL)
        return NULL;


    arr_push(root->left, arr, returnSize);
    arr_push(root->right, arr, returnSize);
    arr[(*returnSize)++] = root->val;


}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;


    int* arr = (int*)malloc(sizeof(int) * 1024);


    arr_push(root, arr, returnSize);


    return arr;
}

int main()
{


	return 0;
}
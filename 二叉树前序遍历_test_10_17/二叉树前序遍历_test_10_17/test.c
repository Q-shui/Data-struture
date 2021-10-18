#include <stdio.h>
#include <malloc.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int TreeSize(struct TreeNode* root);

int* preorderTraversal(struct TreeNode* root, int* returnSize);

int main()
{


	return 0;
}

int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _preorderTraversal(struct TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
        return;

    arr[*pi] = root->val;
    (*pi)++;

    _preorderTraversal(root->left, arr, pi);
    _preorderTraversal(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = TreeSize(root);
    int* arr = malloc(sizeof(int) * *returnSize);

    int i = 0;
    _preorderTraversal(root, arr, &i);

    return arr;
}
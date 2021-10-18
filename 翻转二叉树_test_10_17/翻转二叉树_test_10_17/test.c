#include <stdio.h>

struct TreeNode 
{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
 
struct TreeNode* invertTree(struct TreeNode* root);

void _invertTree(struct TreeNode* root);

int main()
{


	return 0;
}

void _invertTree(struct TreeNode* root)
{
    if (root == NULL)
        return;

    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    _invertTree(root->left);
    _invertTree(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root)
{
    _invertTree(root);

    return root;
}
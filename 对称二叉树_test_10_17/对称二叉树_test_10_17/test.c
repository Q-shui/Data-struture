#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool _isSymmetric(struct TreeNode* root, struct TreeNode* rroot);

bool isSymmetric(struct TreeNode* root);

int main()
{


	return 0;
}

bool _isSymmetric(struct TreeNode* root, struct TreeNode* rroot)
{
    if (root == NULL && rroot == NULL)
        return true;

    if (!(root && rroot))
        return false;

    if (root->val != rroot->val)
        return false;

    return _isSymmetric(root->left, rroot->right) &&
    _isSymmetric(root->right, rroot->left);

}

bool isSymmetric(struct TreeNode* root) 
{
    if (root->left == NULL && root->right == NULL)
        return true;

    if (!(root->left && root->right))
        return false;

    if (root->left->val != root->right->val)
        return false;

    return _isSymmetric(root->left, root->right);

    
}
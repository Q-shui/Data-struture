#include <stdio.h>
#include <stdbool.h>
#include <math.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
    struct TreeNode *right;
 };
 

bool isBalanced(struct TreeNode* root);

int BinaryTreeLevel(struct TreeNode* root);

int main()
{


	return 0;
}

int BinaryTreeLevel(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int leftLevel = BinaryTreeLevel(root->left);
    int rightLevel = BinaryTreeLevel(root->right);


    return 1 + (leftLevel > rightLevel ? leftLevel : rightLevel);
}

bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
        return true;

    int leftlevel = BinaryTreeLevel(root->left);
    int rightlevel = BinaryTreeLevel(root->right);

    if (abs(leftlevel - rightlevel) > 1)
        return false;
    else
        return isBalanced(root->left) && isBalanced(root->right);
}
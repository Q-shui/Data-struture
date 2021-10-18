#include <stdio.h>

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;	
};

int maxDepth(struct TreeNode* root);

int main()
{


	return 0;
}

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

struct TreeNode
{
	char cval;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* CreatTree(char* str, int* pi);

void InOrder(struct TreeNode* str);

int main()
{
	char str[100];
	scanf("%s", &str);
	int i = 0;

	struct TreeNode* root = CreatTree(str, &i);

	InOrder(root);

	return 0;
}

struct TreeNode* CreatTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	root->cval = str[(*pi)++];
	root->left = CreatTree(str, pi);
	root->right = CreatTree(str, pi);

	return root;
}

void InOrder(struct TreeNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%c ", root->cval);
	InOrder(root->right);
}
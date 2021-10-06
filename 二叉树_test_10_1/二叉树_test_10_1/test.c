#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));

	newnode->_data = x;
	newnode->_left = newnode->_right = NULL;

	return newnode;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode('A');
	BTNode* node2 = BuyNode('B');
	BTNode* node3 = BuyNode('C');
	BTNode* node4 = BuyNode('D');
	BTNode* node5 = BuyNode('E');
	BTNode* node6 = BuyNode('F');

	node1->_left = node2;
	node1->_right = node3;
	node2->_left = node4;
	node3->_left = node5;
	node3->_right = node6;
	return node1;
}

int BinaryTreeSize(BTNode* node)
{
	if (node == NULL)
		return 0;
	else
		return 1 + BinaryTreeSize(node->_left) + BinaryTreeSize(node->_right);

}

int BinaryTreeLeafSize(BTNode* node)
{
	if (node == NULL)
	{
		return 0;
	}

	if (node->_left == NULL && node->_right == NULL)
	{
		return 1;
	}
	else
	{
		return 0 + BinaryTreeLeafSize(node->_left) + BinaryTreeLeafSize(node->_right);
	}
}

int BinaryTreeLevelKSize(BTNode* node, int k)
{
	if (node == NULL)
	{
		return 0;
	}

	if (k - 1 == 0)
	{
		return 1;
	}
	else
	{
		return BinaryTreeLevelKSize(node->_left, k - 1) + BinaryTreeLevelKSize(node->_right, k - 1);
	}
}

int BinaryTreeDepth(BTNode* node)
{
	if (node == NULL)
	{
		return 0;
	}

	int leftDepth = BinaryTreeDepth(node->_left);
	int rightDepth = BinaryTreeDepth(node->_right);

	return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

BTNode* BinaryTreeFind(BTNode* node, BTDataType x)
{
	if (node == NULL)
		return NULL;
	
	if (node->_data == x)
		return node;

	BTNode* left = BinaryTreeFind(node->_left, x);
	if (left)
		return left;
	
	BTNode* right = BinaryTreeFind(node->_right, x);
	if (right)
		return right;

	return NULL;

}

int main()
{
	BTNode* node = CreatBinaryTree();

	printf("%d\n", BinaryTreeLeafSize(node));
	printf("%d\n", BinaryTreeLevelKSize(node, 3));
	printf("%d\n", BinaryTreeDepth(node));

	printf("%c\n", BinaryTreeFind(node, 'C')->_data);

	return 0;
}
#include <stdio.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

void Preorder(BTNode* node);
void Inorder(BTNode* node);
void Posorder(BTNode* node);
BTNode* BuyNode(BTDataType x);

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

int main(void)
{
	BTNode* node = CreatBinaryTree();

	Preorder(node);

	return 0;
}

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));

	newnode->_data = x;
	newnode->_left = newnode->_right = NULL;

	return newnode;
}

void Preorder(BTNode* node)
{
	if (node == NULL)
		return NULL;

	printf("%c ", node->_data);
	Preorder(node->_left);
	Preorder(node->_right);
}

void Inorder(BTNode* node)
{
	if (node == NULL)
		return NULL;

	Preorder(node->_left);
	printf("%c ", node->_data);
	Preorder(node->_right);
}

void Posorder(BTNode* node)
{
	if (node == NULL)
		return NULL;

	Preorder(node->_left);
	Preorder(node->_right);
	printf("%c ", node->_data);
}
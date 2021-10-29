#include "Queue.h"



struct BinaryTreeNode* Buynewnode(int x);

void BinaryTreeLevelOrder(struct BinaryTreeNode* root);

int main()
{
	struct BinaryTreeNode* root = Buynewnode(0);
	struct BinaryTreeNode* root1 = Buynewnode(1);
	struct BinaryTreeNode* root2 = Buynewnode(2);
	struct BinaryTreeNode* root3 = Buynewnode(3);
	struct BinaryTreeNode* root4 = Buynewnode(4);
	struct BinaryTreeNode* root5 = Buynewnode(5);
	struct BinaryTreeNode* root6 = Buynewnode(6);
	struct BinaryTreeNode* root7 = Buynewnode(7);

	root->left = root1;
	root->right = root2;
	root1->left = root4;
	root2->right = root6;
	root4->right = root5;
	root6->right = root7;

	BinaryTreeLevelOrder(root);

	return 0;
}

struct BinaryTreeNode* Buynewnode(int x)
{
	struct BinaryTreeNode* newnode = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode*));

	if (newnode == NULL)
	{
		exit(-1);
	}

	newnode->val = x;
	newnode->left = newnode->right = NULL;

	return newnode;
}

void BinaryTreeLevelOrder(struct BinaryTreeNode* root)
{
	Queue q;

	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		struct BinaryTreeNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%d ", front->val);

		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);
		
	}

	printf("\n");

	QueueDestroy(&q);

}

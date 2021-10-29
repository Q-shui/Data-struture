#include "BinaryTree.h"


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->_data = a[(*pi)++];
	newnode->_left = BinaryTreeCreate(a, n, pi);
	newnode->_right = BinaryTreeCreate(a, n, pi);

	return newnode;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	assert(root);

	BTNode** cur = root;

	while (cur)
	{
		BinaryTreeDestory(&(*cur)->_left);
		BinaryTreeDestory(&(*cur)->_right);
		
		free(cur);
	}
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + BinaryTreeSize(root->_left) +
	BinaryTreeSize(root->_right);

}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + 
		BinaryTreeLeafSize(root->_right);


}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (k == 1 && root != NULL)
		return 1;

	if (k != 0)
		return BinaryTreeLevelKSize(root->_left, k - 1) + 
		BinaryTreeLevelKSize(root->_right, k - 1);


}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->_data = x)
		return root;

	return BinaryTreeFind(root->_left, x) || BinaryTreeFind(root->_right, x);


}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);

}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	BinaryTreeInOrder(root->_right);
	printf("%c ", root->_data);
}

// �������
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//
//	if (root == NULL)
//		return;
//
//	QueuePush(&q, root);
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//
//		printf("%c ", front->_data);
//
//		if (front->_left)
//			QueuePush(&q, front->_left);
//
//		if (front->_right)
//			Queuepush(&q, front->_right);
//	}
//
//	//BinaryTreeDestory(&q);
//}

// �ж϶������Ƿ�����ȫ������
//int BinaryTreeComplete(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//
//	QueuePush(&q, root);
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//
//		if (front == NULL)
//		{
//			break;
//		}
//
//		QueuePush(&q, front->_left);
//		Queuepush(&q, front->_right);
//	}
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//
//		if (front)
//		{
//			QueueDestroy(&q);
//			return 0;
//		}
//
//	}
//
//	return 1;
//}
//

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <malloc.h>



typedef struct BinaryTreeNode* QDataType;
//typedef struct BinaryTreeNode BTDatatype;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

struct BinaryTreeNode
{
	int val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

};

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);

// ��β����� 
void QueuePush(Queue* q, QDataType data);

// ��ͷ������ 
void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);

// ���ٶ��� 
void QueueDestroy(Queue* q);
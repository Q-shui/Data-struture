#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>

typedef int QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

//创建两个队列
typedef struct
{
	Queue q1;
	Queue q2;
}MyStack;

// 初始化队列 
void QueueInit(Queue* q);

// 队尾入队列 
void QueuePush(Queue* q, QDataType data);

// 队头出队列 
void QueuePop(Queue* q);

// 获取队列头部元素 
QDataType QueueFront(Queue* q);

// 获取队列队尾元素 
QDataType QueueBack(Queue* q);

// 获取队列中有效元素个数 
int QueueSize(Queue* q);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);

// 销毁队列 
void QueueDestroy(Queue* q);

//创建一个栈
MyStack* myStackCreate();

//压栈
void myStackPush(MyStack* obj, int x);

//出栈
int myStackPop(MyStack* obj);

//返回栈顶元素
int myStackTop(MyStack* obj);

//判断栈是否为空
bool myStackEmpty(MyStack* obj);

//销毁栈
void myStackFree(MyStack* obj);


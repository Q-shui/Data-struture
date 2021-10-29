#include "Queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);

	q->_front = q->_rear = NULL;

}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	newnode->_data = data;
	newnode->_next = NULL;

	if (q->_rear == NULL)
		q->_rear = q->_front = newnode;
	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;;
	}

}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);

	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else
	{
		QNode* tmp = q->_front->_next;
		free(q->_front);
		q->_front = tmp;
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);

	QNode* cur = q->_front;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}

	return size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_rear == NULL;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	//assert(!QueueEmpty(q));

	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

#include "myStack.h"

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
	{
		q->_front = q->_rear = newnode;
	}
	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	if (q->_front->_next == NULL)
	{
		q->_front = q->_rear = NULL;
	}
	else
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
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

	return q->_front == NULL;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->_front;

	while (cur)
	{
		QNode* next = q->_front->_next;
		free(cur);
		cur = next;
	}

	q->_front = q->_rear = NULL;

}

//创建一个栈
MyStack* myStackCreate()
{
	MyStack* newnode = (MyStack*)malloc(sizeof(MyStack));

	QueueInit(&newnode->q1);
	QueueInit(&newnode->q2);

	return newnode;
}

//压栈
void myStackPush(MyStack* obj, int x)
{
	assert(obj);

	if (!QueueEmpty(&obj->q1))
		QueuePush(&obj->q1, x);
	else
		QueuePush(&obj->q2, x);
}

//出栈
int myStackPop(MyStack* obj)
{
	assert(obj);
	assert(!myStackEmpty(obj));

	Queue* emptyQ = &obj->q1;
	Queue* noneemptyQ = &obj->q2;

	if (QueueEmpty(&obj->q2))
	{
		emptyQ = &obj->q2;
		noneemptyQ = &obj->q1;
	}

	while (QueueSize(noneemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(noneemptyQ));
		QueuePop(noneemptyQ);
	}

	int top = QueueFront(noneemptyQ);
	QueuePop(noneemptyQ);

	return top;
}

//返回栈顶元素
int myStackTop(MyStack* obj)
{
	assert(obj);
	assert(!myStackEmpty(obj));

	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

//判断栈是否为空
bool myStackEmpty(MyStack* obj)
{
	assert(obj);
	
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//销毁栈
void myStackFree(MyStack* obj)
{
	assert(obj);

	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}



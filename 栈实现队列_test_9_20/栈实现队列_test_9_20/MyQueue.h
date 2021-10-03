#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <malloc.h>

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

typedef struct
{
	Stack emptyS;
	Stack noneemptyS;

} MyQueue;

// 初始化栈 
void StackInit(Stack* ps);

// 入栈 
void StackPush(Stack* ps, STDataType data);

// 出栈 
void StackPop(Stack* ps);

// 获取栈顶元素 
STDataType StackTop(Stack* ps);

// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);

// 销毁栈 
void StackDestroy(Stack* ps);



/** Initialize your data structure here. */

MyQueue* myQueueCreate();

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x);

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj);

/** Get the front element. */
int myQueuePeek(MyQueue* obj);

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj);

void myQueueFree(MyQueue* obj);

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/


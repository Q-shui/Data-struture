#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>

typedef struct
{
    int* a;
    int front;
    int rear;
    int k;
} MyCircularQueue;

//判断队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

//判断队列是否已满
bool myCircularQueueIsFull(MyCircularQueue* obj);

//创建队列
MyCircularQueue* myCircularQueueCreate(int k);

//插入原元素
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);

//删除元素
bool myCircularQueueDeQueue(MyCircularQueue* obj);

//获取队首元素
int myCircularQueueFront(MyCircularQueue* obj);

//获取队尾元素
int myCircularQueueRear(MyCircularQueue* obj);

//销毁队列
void myCircularQueueFree(MyCircularQueue* obj);

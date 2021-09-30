#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int SQDataType;

typedef struct SeqList
{
	SQDataType* a;
	int size;//数据个数
	int capacity;//容量空间大小
}SLT;


void SeqListInit(SLT* ps1);//初始化

void SeqListDestory(SLT* ps1);//销毁

void SeqListPrint(SLT* ps1);//打印顺序表

void SeqListCheckCapacity(SLT* ps1);//检查容量是否满

//增删查改

void SeqListPushBack(SLT* ps1, SQDataType x);//尾插

void SeqListPushFront(SLT* ps1);//尾删


void SeqListPopback(SLT* s1, SQDataType x);//头插

void SeqListPopFront(SLT* s1);//头删


int SeqListFind(SLT* s1, SQDataType x);//查找

void SeqListInsert(SLT* s1, int pos, SQDataType x);//中间插入

void SeqListErase(SLT* s1, int pos);//指定位置的删除

size_t SeqListSize(SLT* ps1);

void SeqListAt(SLT* ps1, int pos, SQDataType x);

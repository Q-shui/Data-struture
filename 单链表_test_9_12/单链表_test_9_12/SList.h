#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int SLTDataType;


typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

// 动态申请一个节点
SLTNode* BuySListNode(SLTDataType x);

// 单链表打印
void SListPrint(SLTNode* plist);

// 单链表尾插
void SListPushBack(SLTNode** pplist, SLTDataType x);

// 单链表的头插
void SListPushFront(SLTNode** pplist, SLTDataType x);

// 单链表的尾删
void SListPopBack(SLTNode** pplist);
// 单链表头删
void SListPopFront(SLTNode** pplist);

//单链表长度
int SListSize(SLTNode* plist);

//单链表是否为空
bool SListEmpty(SLTNode* plist);

// 单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//单链表顺序向右，pos位置之前需要用到双指针
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsert(SLTNode** pplist, SLTNode* pos, SLTDataType x);
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListErase(SLTNode** pplist, SLTNode* pos);
void SListEraseAfter(SLTNode* pos);

//链表的销毁
void SListDestory(SLTNode** pplist);
#include "SList.h"

// 动态申请一个节点
SLTNode* BuySListNode(SLTDataType x)
{

	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));

	if (newnode == NULL)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;

}

// 单链表打印
void SListPrint(SLTNode* plist)
{

	SLTNode* cur = plist;

	while (cur != NULL)
	{
		printf("%d->", cur->data);

		cur = cur->next;

	}

	printf("NULL\n");

}

// 单链表尾插
void SListPushBack(SLTNode** pplist, SLTDataType x)
{

	if (*pplist == NULL)
	{

		SLTNode* newnode = BuySListNode(x);

		*pplist = newnode;

	}
	else
	{

		SLTNode* tail = *pplist;

		while (tail->next != NULL)
		{

			tail = tail->next;

		}

		SLTNode* newnode = BuySListNode(x);

		tail->next = newnode;

	}
	

}

// 单链表的头插
void SListPushFront(SLTNode** pplist, SLTDataType x)
{

	assert(pplist);

	SLTNode* newnode = BuySListNode(x);

	newnode->next = *pplist;
	*pplist = newnode;


}

// 单链表的尾删
void SListPopBack(SLTNode** pplist)
{

}

// 单链表头删
void SListPopFront(SLTNode** pplist)
{

}

// 单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{

}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{

}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SLTNode* pos)
{

}

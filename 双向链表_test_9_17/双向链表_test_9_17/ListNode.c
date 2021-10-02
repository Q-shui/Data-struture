#include "ListNode.h"


//创建一块空间
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;

	return node;

}
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* node = BuyListNode(-1);

	node->_prev = node;
	node->_next = node;

	return node;

}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->_next;

	while (cur != pHead)
	{
		ListNode* tmp = cur->_next;
		free(cur);
		cur = tmp;;
	}

	free(pHead);
	pHead = NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->_next;

	while (cur != pHead)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}

	printf("\n");

}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newnode = BuyListNode(x);
	ListNode* tail = pHead->_prev;

	newnode->_prev = tail;
	tail->_next = newnode;

	newnode->_next = pHead;
	pHead->_prev = newnode;
	

}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);

	ListNode* tail = pHead->_prev;
	ListNode* tailPrev = tail->_prev;

	tailPrev->_next = pHead;
	pHead->_prev = tailPrev;

	free(tail);


}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newnode = BuyListNode(x);
	ListNode* head = pHead->_next;

	pHead->_next = newnode;
	newnode->_prev = pHead;
	newnode->_next = head;
	head->_prev = newnode;
	
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);

	ListNode* head = pHead->_next;
	ListNode* newhead = head->_next;

	pHead->_next = newhead;
	newhead->_prev = pHead;

	free(head);


}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* cur = pHead->_next;

	while (cur != pHead)
	{
		if (cur->_data == x)
			return cur;
		
		cur = cur->_next;
	}

	return NULL;

}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = BuyListNode(x);
	ListNode* posPrev = pos->_prev;

	posPrev->_next = newnode;
	newnode->_prev = posPrev;
	newnode->_next = pos;
	pos->_prev = newnode;

}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->_prev;

	posPrev->_next = pos->_next;
	pos->_next->_prev = posPrev;

	free(pos);

}
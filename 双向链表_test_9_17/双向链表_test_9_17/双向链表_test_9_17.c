#include"ListNode.h"

void Test1();

int main(void)
{
	Test1();

	return 0;
}

void Test1()
{
	ListNode* plist = NULL;
	
	plist = ListCreate();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);

	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListInsert(ListFind(plist, 4), 6);
	ListPrint(plist);

	ListErase(ListFind(plist, 6));
	ListPrint(plist);

	ListDestory(plist);
}
#include "SList.h"


void Test1();

void Test2();


int main(void)
{
	//Test1();
	Test2();

	return 0;

}


void Test1()
{

	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	n1->data = 1;
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	n2->data = 2;
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	n3->data = 3;
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	n4->data = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	SLTNode* plist = n1;

	SListPrint(plist);
}

void Test2()
{

	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);//空链表尾插有问题
	SListPushBack(&plist, 2);//需要再加入一个判断
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPushFront(&plist, -1);//空链表头插无问题

	SListPopBack(&plist);

	SListPopFront(&plist);
	
	if (SListFind(plist, 3))
	{

		printf("找到了\n");

	}
	SLTNode* pos = SListFind(plist, 2);

	if (pos)
	{

		//SListInsert(&plist, pos, 10);
		//SListInsertAfter(pos, 20);
		//SListEraseAfter(pos);
		//SListErase(&plist, pos);
	}

	SListPrint(plist);
	
	printf("SListSize:%d\n", SListSize(plist));
	printf("SListEmpty:%d\n", SListEmpty(plist));

}
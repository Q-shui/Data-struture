#include "MyQueue.h"

void Test1();//栈的测试
void Test2();//栈实现队列的测试

int main(void)
{
	//Test1();
	Test2();
	return 0;
}

void Test1()
{
	Stack st;

	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackPop(&st);

	printf("%d\n", StackTop(&st));
	printf("%d\n", StackSize(&st));
	printf("%d\n", StackEmpty(&st));

}

void Test2()
{
	MyQueue* sq = myQueueCreate();

	myQueuePush(sq, 1);
	myQueuePush(sq, 2);

	printf("%d\n", myQueuePeek(sq));
	printf("%d\n", myQueuePop(sq));
	printf("%d\n", myQueueEmpty(sq));

	myQueueFree(sq);

}
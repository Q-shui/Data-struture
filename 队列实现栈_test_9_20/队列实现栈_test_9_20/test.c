#include "myStack.h"

void Test1();
void Test2();

int main(void)
{
	Test1();
	Test2();
	return 0;
}

//队列测试
void Test1()
{
	Queue qt;
	QueueInit(&qt);

	QueuePush(&qt, 1);
	QueuePush(&qt, 2);
	QueuePush(&qt, 3);

	QueuePop(&qt);

	printf("%d\n", QueueFront(&qt));
	printf("%d\n", QueueBack(&qt));
	printf("%d\n", QueueSize(&qt));
	printf("%d\n", QueueEmpty(&qt));

	QueueDestroy(&qt);

}

//队列实现栈测试
void Test2()
{
	MyStack* st = myStackCreate();

	myStackPush(st, 1);
	myStackPush(st, 2);

	printf("%d\n", myStackTop(st));
	printf("%d\n", myStackPop(st));
	printf("%d\n", myStackEmpty(st));
}
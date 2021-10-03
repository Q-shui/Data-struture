#include "Stack.h"

void Test1();//Õ»µÄ²âÊÔ


int main(void)
{
	Test1();
	
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


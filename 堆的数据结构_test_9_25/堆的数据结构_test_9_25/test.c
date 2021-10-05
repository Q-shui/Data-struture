#include "Heap.h"

void Test1();
void Test2();

int main(void)
{
	Test1();

	printf("\n\n\n");

	Test2();

	return 0;
}

void Test1()
{
	Heap hp;

	int a[] = { 27, 37, 28, 18, 19, 34, 65, 25, 49, 15 };

	HeapCreate(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);

	printf("\n");

	HeapPush(&hp, 98);
	HeapPrint(&hp);

	printf("\n");

	HeapPop(&hp);
	HeapPrint(&hp);

	printf("\n");

	printf("%d\n", HeapTop(&hp));
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapEmpty(&hp));

	HeapDestroy(&hp);
}

void Test2()
{
	TestTopk();
}
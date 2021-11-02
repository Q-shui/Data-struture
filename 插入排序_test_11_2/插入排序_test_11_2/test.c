#include "Sort.h"

int main()
{
	int a[] = { 14, 46, 23, 4, 8, 3, 547, 423, 432, 56 };

	int sz = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, sz);

	ShellSort(a, sz);

	PrintArray(a, sz);
	
	return 0;
}
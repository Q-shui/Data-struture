#include <stdio.h>

void HeapPrint(int* a, int n);
void Swap(int* py, int* px);
void Adjustup(int* a, int child);
void Heap(int* a, int n);



int main(void)
{
	int a[] = { 27, 37, 28, 18, 19, 34, 65, 25, 49, 15 };

	Heap(a, sizeof(a) / sizeof(a[0]));

	HeapPrint(a, sizeof(a) / sizeof(a[0]));

	return 0;
}

void HeapPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void Swap(int* py, int* px)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void Adjustup(int* a, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void Heap(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		Adjustup(a, i);
	}
}
#include <stdio.h>

void Swap(int* a, int* b);

int PartSort(int* a, int left, int right);

void QuickSort(int* a, int left, int right);

void PrintArray(int* a, int n);

int main()
{
	int a[] = { 10, 3, 7, 2, 9, 5 ,3, 5 , 6, 8 };
	int sz = sizeof(a) / sizeof(a[0]);

	QuickSort(a, 0, sz - 1);
	PrintArray(a, sz);

	return 0;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int PartSort(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
			--right;
		while (left < right && a[left] <= a[keyi])
			++left;

		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[right]);

	return left;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyi = PartSort(a, left, right);

	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}
#include <stdio.h>
#include "Stack.h"

int GetMiddleIndex(int* a, int left, int right);

void Swap(int* a, int* b);

int PartSort1(int* a, int left, int right);

int PartSort2(int* a, int left, int right);

int PartSort3(int* a, int left, int right);

void QuickSortnonr(int* a, int left, int right);

void QuickSort(int* a, int left, int right);

void PrintArray(int* a, int n);

int main()
{
	int a1[] = { 10, 3, 7, 2, 9, 5 ,3, 5 , 6, 8 };
	int a2[] = { 10, 3, 7, 2, 9, 5 ,3, 5 , 6, 8 };

	int sz = sizeof(a1) / sizeof(a1[0]);

	QuickSort(a1, 0, sz - 1);
	QuickSortnonr(a2, 0, sz - 1);
	PrintArray(a1, sz);
	PrintArray(a2, sz);

	return 0;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int PartSort1(int* a, int left, int right)
{
	int midi = GetMiddleIndex(a, left, right);
	Swap(&a[left], &a[midi]);

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

	//int keyi = PartSort1(a, left, right);
	//int keyi = PartSort2(a, left, right);
	int keyi = PartSort2(a, left, right);

	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int GetMiddleIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[a[right] < a[left]])
			return right;
		else
			return left;
	}
}

//int PartSort2(int* a, int left, int right)
//{
//	int mid = GetMiddleIndex(a, left, right);
//	Swap(&a[left], &a[right]);
//
//	while (left < right)
//	{
//		while (a[right] > a[left])
//			--right;
//		if (right <= left)
//			break;
//		Swap(&a[right], &a[left]);
//		++left;
//		while (a[left] < a[right])
//			++left;
//		if (right <= left)
//			break;
//		Swap(&a[left], &a[right]);
//		--right;
//	}
//
//	return left;
//}


int PartSort2(int* a, int left, int right)
{
	int mid = GetMiddleIndex(a, left, right);
	Swap(&a[left], &a[right]);

	int key = a[left];
	int hole = left;

	while (left < right)
	{
		while (left < right && a[right] >= key)
			--right;
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)
			++left;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int left, int right)
{
	int mid = GetMiddleIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[left] && ++prev != cur)
		{	
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}

	Swap(&a[left], &a[prev]);
	return prev;
}

void QuickSortnonr(int* a, int left, int right)
{
	ST st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);

		int end = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, begin, end);

		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}

		if (begin < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
	}
}
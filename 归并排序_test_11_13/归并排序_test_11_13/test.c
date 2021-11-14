#include <stdio.h>
#include <malloc.h>

//¹é²¢ÅÅÐò
void _MergeSort(int* a, int left, int right, int* tmp);

void MergeSort(int* a, int n);

void CountSort(int* a, int n);

void PrintArray(int* a, int sz);

int main()
{
	int a[] = { 10, 3, 7, 2, 9, 5 ,3, 5 , 6, 8 };
	int sz = sizeof(a) / sizeof(a[0]);

	MergeSort(a, sz);
	PrintArray(a, sz);


	return 0;
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;

	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	for (int i = left; i <= right; ++i)
		a[i] = tmp[i];
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void PrintArray(int* a, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void CountSort(int* a, int n)
{

}


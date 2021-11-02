#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int k = i; k > -1; --k)
//		{
//			if (a[k + 1] > a[k])
//				break;
//			else
//			{
//				int tmp = a[k + 1];
//				a[k + 1] = a[k];
//				a[k] = tmp;
//			}
//		}
//	}
//}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] < tmp)
				break;
			else
			{
				a[end + 1] = a[end];
				--end;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];

			while (end >= 0)
			{
				if (a[end] < tmp)
					break;
				else
				{
					a[end + gap] = a[end];
					end -= gap;
				}

				a[end + gap] = tmp;
			}
		}
	}

}
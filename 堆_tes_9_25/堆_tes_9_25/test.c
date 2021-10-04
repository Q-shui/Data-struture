#include <stdio.h>

//交换函数
void Swap(int* px, int* py);

//向下调整算法
void Adjustdown(int* a, int n, int parent);

//堆排序
void Heapsort(int* a, int n);

//测试代码
void Test();

int main(void)
{
	Test();

	return 0;
}

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py; 
	*py = tmp;
}

void Adjustdown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}

}

void Heapsort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		Adjustdown(a, n, i);
	for (int i = 1; i < n; i++)
	{
		Swap(&a[0], &a[n - i]);
		Adjustdown(a, n - i, 0);
	}

}

void Test()
{
	int a[] = { 27, 37, 28, 18, 19, 34, 65, 25, 49, 15 };

	Heapsort(a, sizeof(a) / sizeof(a[0]));

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d ", a[i]);
}


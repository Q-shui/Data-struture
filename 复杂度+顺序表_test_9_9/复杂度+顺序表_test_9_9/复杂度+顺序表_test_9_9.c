#define _CRT_SECURE_NO_WARNINGS




////空间复杂度
//
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}//O(1)常数个变量
//
//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;
//
//	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}//O(n)
//
//long long Fac(size_t N)
//{
//	if (N == 0)
//		return 1;
//
//	return Fac(N - 1) * N;
//}//O(n)
//
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fib(N - 1) + Fib(N - 2);
//}//O(n)  函数的栈帧的创建

//顺序表

//访问数据结构中的数据尽量用函数去访问

#include "SeqList.h"

void TestSeqList1();//初步测试程序

int main(void)
{
	TestSeqList1();

	return 0;
}

void TestSeqList1()
{
	SLT s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 1);

	SeqListPushFront(&s);


	SeqListPopback(&s, 3);

	SeqListPopFront(&s);

	SeqListInsert(&s, 1, 10);//多考虑一些极端情况

	SeqListErase(&s, 0);

	printf("查找的数据位置为%d\n", SeqListFind(&s, 10));

	

	SeqListPrint(&s);

	SeqListDestory(&s);
}

//还可以适当加个菜单
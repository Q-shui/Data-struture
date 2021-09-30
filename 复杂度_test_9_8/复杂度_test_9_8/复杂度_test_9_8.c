#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//时间复杂度

void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}

	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);

}//O(n^2)

void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}//O(n)

void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; ++k)
	{
		++count;
	}
	for (int k = 0; k < N; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}//O(m+n)

void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}//O(1)

const char* strchr(const char* str, int character);
//O(n)

void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}//O(n^2)

int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}
	return -1;
}//O(log2(n))


long long Fac(size_t N)
{
	if (0 == N)
		return 1;

	return Fac(N - 1) * N;
}//O(n)

long long Fib(size_t N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}//O(2^n)

//作业
//数字的出现次数

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	int a = 0;
	for (int i = 0; i < numsSize; i++)
	{
		a ^= nums[i];
	}

	a = a & (-1 * a);

	int* result = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	result[0] = 0;
	result[1] = 0;


	for (int i = 0; i < numsSize; i++)
	{
		if ((nums[i] & a) == 0)
		{
			result[0] ^= nums[i];
		}
		else
		{
			result[1] ^= nums[i];
		}
	}
	return result;
}

//消失的数字
int missingNumber(int* nums, int numsSize)
{
	long long sum = 0;


	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
	}


	return (numsSize * (numsSize + 1)) / 2 - sum;
}


int main(void)
{

	return 0;
}
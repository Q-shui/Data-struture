#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool IsPrimeNumber(int n);
int SumofPrimeNumber(int n);
void Test1();
void Test2(int n);
void Test3();//¶ÓÁÐ²Ù×÷
void Test4();

int main(void)
{
	//Test1();
	//Test2(210);
	Test4();

	return 0;
}

bool IsPrimeNumber(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int SumofPrimeNumber(int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			sum += i;
	}

	return sum;

}


void Test1()
{
	double a = 1.0, b = 1.0;
	double sums = 0.0;

	for (int i = 1; i <= 30; i++)
	{
		double c = a + b;
		sums += c / a;
		double d = c;
		c = a + d;
		a = d;
	}

	printf("%lf", sums);

}

void Test2(int n)
{
	for (int i = 2; i < n; i++)
	{
		if ((n % i == 0) && IsPrimeNumber(i))
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

void Test3()
{

}

void Test4()
{
	for (int i = 1; i < 10000; i++)
	{
		for (int j = i + 1; j < 10000; j++)
		{
			if (SumofPrimeNumber(i) == j && SumofPrimeNumber(j) == i)
				printf("%d %d\n", i, j);
		}
	}
}


#include "Heap.h"

//��������
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//���µ����㷨
void Adjustdown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
			++child;
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}

}

//���ϵ����㷨
void Adjustup(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

//������
void Heapsort(int* a, int n)
{
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		Adjustdown(a, n, i);
	for (int i = 1; i < n; i++)
	{
		Swap(&a[0], &a[n - i]);
		Adjustdown(a, n - i, 0);
	}

}
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);

	if (hp->_a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	memcpy(hp->_a, a, sizeof(HPDataType) * n);

	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		Adjustdown(hp->_a, n, i);

	hp->_capacity = hp->_size = n;

}

// �ѵ�����
void HeapDestroy(Heap* hp)
{
	assert(hp);

	free(hp->_a);
	hp->_capacity = hp->_size = 0;

}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	if (hp->_size == hp->_capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, hp->_capacity * 2 * sizeof(HPDataType));

		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		hp->_capacity *= 2;
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	Adjustup(hp->_a, hp->_size - 1);
}

// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);

	hp->_size--;

	Adjustdown(hp->_a, hp->_size, 0);

}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	return hp->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->_size;
}

// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->_size == 0;
}

//�ѵĴ�ӡ
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
		printf("%d ", hp->_a[i]);
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	Heap hp;

	HeapCreate(&hp, a, k);

	for (int i = k; i < n; i++)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	HeapPrint(&hp);

	HeapDestroy(&hp);
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
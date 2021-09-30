#include "SeqList.h"

void SeqListInit(SLT* ps1)
{
	ps1->a = NULL;
	ps1->size = ps1->capacity = 0;
}

void SeqListDestory(SLT* ps1)
{
	assert(ps1);

	if (ps1->a)
	{
		free(ps1->a);
		ps1->a = NULL;
	}

	ps1->size = ps1->capacity = 0;
}

void SeqListPrint(SLT* ps1)
{
	assert(ps1);

	for (int i = 0; i < ps1->size; i++)
	{
		printf("%d\n", ps1->a[i]);
	}
}

void SeqListCheckCapacity(SLT* ps1)
{
	if (ps1->size == ps1->capacity)
	{
		size_t newcapacity = ps1->capacity == 0 ? 4 : ps1->capacity * 2;
		ps1->a = realloc(ps1->a, newcapacity * sizeof(SQDataType));
		ps1->capacity = newcapacity;
	}
}

void SeqListPushBack(SLT* ps1, SQDataType x)
{
	assert(ps1);

	SeqListCheckCapacity(ps1);

	ps1->a[ps1->size] = x;
	ps1->size++;

}

void SeqListPushFront(SLT* ps1)
{
	assert(ps1);

	ps1->size--;

}

void SeqListPopback(SLT* ps1, SQDataType x)
{
	assert(ps1);

	SeqListCheckCapacity(ps1);

	int end = ps1->size - 1;

	while (end >= 0)
	{
		ps1->a[end + 1] = ps1->a[end];
		end--;
	}

	ps1->a[0] = x;
	ps1->size++;

}

void SeqListPopFront(SLT* ps1)
{
	assert(ps1);

	for (int i = 1; i < ps1->size; i++)
	{
		ps1->a[i - 1] = ps1->a[i];
	}

	ps1->size--;

}


int SeqListFind(SLT* ps1, SQDataType x)
{
	assert(ps1);

	for (int i = 0; i < ps1->size; i++)
	{
		if (ps1->a[i] == x)
		{
			return i + 1;
		}
	}

	return -1;

}


//可以用size_t类型的pos
void SeqListInsert(SLT* ps1, int pos, SQDataType x)
{
	assert(ps1);
	assert(pos - 1 <= ps1->size);

	SeqListCheckCapacity(ps1);

	for (int i = ps1->size - 1; i > pos - 1; i--)
	{
		ps1->a[i + 1] = ps1->a[i];
	}

	ps1->a[pos - 1] = x;

	ps1->size++;

}

void SeqListErase(SLT* ps1, int pos)
{
	assert(ps1);
	assert(pos <= ps1->size);

	for (int i = pos; i < ps1->size - 1; i++)
	{
		ps1->a[i] = ps1->a[i + 1];

	}

	ps1->size--;

}

size_t SeqListSize(SLT* ps1)
{
	assewrt(ps1);

	return ps1->size;

}

void SeqListAt(SLT* ps1, int pos, SQDataType x)
{
	assert(ps1);

	ps1->a[pos] = x;

}
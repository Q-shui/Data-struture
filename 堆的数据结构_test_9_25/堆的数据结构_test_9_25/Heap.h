#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//��������
void Swap(int* px, int* py);

//���µ����㷨
void Adjustdown(int* a, int n, int parent);

//���ϵ����㷨
void Adjustup(int* a, int child);

//������
void Heapsort(int* a, int n);

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);

// �ѵ�����
void HeapDestroy(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp);

//�ѵĴ�ӡ
void HeapPrint(Heap* hp);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);

void TestTopk();

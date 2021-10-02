#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);

void StackDestory(ST* ps);

void StackPush(ST* ps, STDataType x);

void StackPop(ST* ps);

bool StackEmpty(ST* ps);

STDataType StackTop(ST* ps);

int StackSize(ST* ps);
#pragma once
//栈只要尾插 尾删
typedef int SDataType;

#include<stdio.h>
#define MAX_SIZE (100)
#include<assert.h>
#include<stdlib.h>

typedef struct
{
	SDataType array[MAX_SIZE];
	int top;//size别名 含义一样
}Stack;

void StackInit(Stack *pS)
{
	pS->top = 0;
}

void StackDestroy(Stack *pS)
{
	pS->top = 0;
}

//尾插
void StackPush(Stack *pS, SDataType data)
{
	assert(pS->top < MAX_SIZE);
	pS->array[pS->top++] = data;
}

//尾删
void StackPop(Stack *pS)
{
	assert(pS->top>0);
	pS->top--;

}

//只能从栈顶取元素
SDataType StackTop(const Stack *pS)
{
	assert(pS->top > 0);
	return pS->array[pS->top - 1];
}


int StackSize(const Stack *pS)
{
	return pS->top;
}

int StackEmpty(const Stack *pS)
{
	return pS->top == 0 ? 1 : 0;
}


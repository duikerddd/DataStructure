#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DDataType;

typedef struct{
	DDataType *array;
	int size;
	int capacity;     //容量 MAX_SIZE
}SeqListD;

void SeqListDInit(SeqListD *pSeq)
{
	const int init_capacity = 5;
	assert(pSeq != NULL);
	pSeq->size = 0;
	pSeq->capacity = init_capacity;
	pSeq->array = (DDataType *)malloc(sizeof(DDataType)*init_capacity);
	assert(pSeq->array);

}

void SeqListDDestory(SeqListD *pSeq)
{
	free(pSeq->array);
	pSeq->array = NULL;
	pSeq->size = 0;
	pSeq->capacity = 0;
}

void ExpandIfRequired(SeqListD *pSeq)
{
	//不需要扩容
	if (pSeq->size < pSeq->capacity)
	{
		return;
	}

	//肯定要扩容
	int newCapacity = pSeq->capacity * 2;//扩容一般给2倍  伙伴算法
	DDataType *newArray = (DDataType *)malloc(sizeof(DDataType)*newCapacity);
	assert(newArray);

	//搬移老的数据到新的数组里来
	for (int i = 0; i < pSeq->size; i++)
	{
		newArray[i] = pSeq->array[i];
	}

	//释放老数组
	free(pSeq->array);
	//新数组放到顺序表结构体里
	pSeq->array = newArray;
	//更新capacity;
	pSeq->capacity = newCapacity;

}

//插入的时候需要扩容 头插/尾插/中间插 ,演示尾插
void SeqListPushBack(SeqListD *pSeq, DDataType data)
{
	assert(pSeq);
	//考虑扩容的事情
	ExpandIfRequired(pSeq);


	pSeq->array[pSeq->size] = data;

}


void Test()
{
	SeqListD seq;
	SeqListDInit(&seq);
}

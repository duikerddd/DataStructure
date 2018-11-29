//链表
//      单向链表       双向链表
//      不带头链表     带头链表
//		不循环链表     循环链表
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef struct DNode
{
	struct  DNode*prev;
	struct  DNode*next;
	int data;
}DNode;

DNode *CreateDNode(int data)
{
	DNode *node = (DNode*)malloc(sizeof(DNode));
	node->data = data;
	node->next = node->prev = NULL;
	return node;

}

//初始化
void DListInit(DNode **ppHead)
{
	assert(ppHead != NULL);
	DNode *node = CreateDNode(0);  //这个0其实也没用可以当成size用

	node->prev = node;
	node->next = node;
	*ppHead = node;
}


//清空链表(保留头结点)
void DListClear(DNode *head)
{
	DNode *next;
	for (DNode *cur = head->next; cur != head; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	head->prev = head->next = head;
}

//TODO 销毁
void DListDestroy(DNode *head)
{
	DListClear(head);
	free(head);
}

//插入到pos的前面(pos一定在链表中)
void DListInsert(DNode *head, DNode *pos, int data)
{
	DNode *node = CreateDNode(data);
	node->prev = pos->prev;
	node->next = pos;
	pos->prev->next = node;
	pos->prev = node;
}

//头插
//和单链表区别 不需要二级指针
void DListPushFront(DNode *head, int data)
{

	DListInsert(head, head->next, data);
#if 0
	DNode *node = CreateDNode(data);
	node->prev = head;
	node->next = head->next;

	head->next->prev = node;
	head->next = node;
#endif
}

//尾插
void DListPushBack(DNode *head, int data)
{

	DListInsert(head, head, data);
#if 0
	DNode *node = CreateDNode(data);
	node->prev = head->prev;
	node->next = head;

	head->prev->next = node;
	head->prev = node;
#endif
}

//删除
void DListErase(DNode *head, DNode *pos)
{
	assert(head->next != head);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//头删
void DListPopFront(DNode *head)
{
	DListErase(head, head->next);
#if 0
	assert(head->next != head);
	DNode *first = head->next;
	DNode *second = head->next->next;
	head->next = second;
	second->prev = head;
	free(first);
#endif
}

//尾删除
void DListPopBack(DNode *head)
{
	DListErase(head, head->prev);
#if 0
	assert(head->next != head);
	DNode *node = head->prev;
	head->prev->next = head;
	head->prev = node->prev;
	free(node);
#endif
}



void Print(DNode *head)
{
	for (DNode*cur = head->next; cur != head; cur = cur->next)
	{
		printf("%d ", cur->data);
	}
	printf("\n");
}

void Test()
{
	DNode *list;
	DListInit(&list);
	//链表有个头结点
	DListPushFront(list, 12);


	Print(list);
}


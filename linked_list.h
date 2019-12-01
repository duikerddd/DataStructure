#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;

//这只是第一个结构 表示结点 而不是表示链表
//next地址指向下一个结构
typedef struct Node
{
	DataType data;
	struct Node*next;
}Node;

//空的链表(链表里一个结点都没有)   Node *p==NULL

//链表的初始化 构造一条空的链表 将第一个结构体指针变为NULL
void SListInit(Node **ppfirst)
{
	assert(ppfirst != NULL);  
	*ppfirst = NULL;
}
//链表的销毁 需要销毁每一个结点
void SListDestroy(Node *first)
{
	Node*cur,*next;
	for (cur = first; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
}


//头插一个0
// 1.要来一个结点空间 malloc ox100{0,NULL}

void SListPushFront(Node **ppfirst, DataType data)
{
	assert(ppfirst != NULL);

	//正常情况
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	/*node->next = NULL;*/

	node->next = *ppfirst; 
	*ppfirst = node;
	
}


//预处理 编译 汇编 链接
static Node* CreateNode(DataType data)
{
	Node*node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}
//尾插
//1.申请空间 0xA00{0,NULL}
//2.找到最后一个结点组后一个结点的next=0xA00
void SListPushBack(Node**ppfirst,DataType data)
{
	Node* node = CreateNode(data);
	if (*ppfirst == NULL)
	{
		*ppfirst = node;
		return;
	}
	//找链表最后一个结点,链表中至少有一个结点
	

	Node *cur = *ppfirst;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
}
 
//插入,在结点pos前面插入
void SListInsert(Node**ppfirst,Node* pos, DataType data)
{
	if (*ppfirst == pos)
	{
		SListPushFront(ppfirst, data);
		return;
	}
	Node* newNode = CreateNode(data); //***不要忘了申请空间
	Node* cur;
	//找到pos前面的一个结点
	for (cur = *ppfirst; cur->next != pos; cur = cur->next)
	{
	}

	//改变的是字段内的值,而不是指针的值
	cur->next = newNode;
	newNode->next = pos;
}


//删除
//头删
void SListPopFront(Node**ppfirst)
{
	assert(ppfirst != NULL);
	assert(*ppfirst != NULL);//链表不是空链表

	Node *first = *ppfirst;
	*ppfirst = (*ppfirst)->next;
	free(first);
}

//尾删
//1.找到倒数第二个结点
//cur->next->next=null;
void SListPopBack(Node**ppfirst)
{
	assert(ppfirst != NULL);
	assert(*ppfirst != NULL);//链表不是空链表

	if ((*ppfirst)->next == NULL)
	{
		free(*ppfirst);
		*ppfirst = NULL;
		return;
	}

	//链表中至少有两个结点,才能找到倒数第二个
	Node* cur = *ppfirst;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}


//删除 pos一定在链表中
void SListErase(Node **ppfirst, Node *pos)
{
	if (*ppfirst == pos)
	{
		SListPopFront(ppfirst);
	}

	Node *cur = *ppfirst;
	while (cur->next!=pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
}

//查找(顺序查找)
//找到返回所在结点地址,没找到返回NULL
Node* SListFind(Node*first, DataType data)
{
	for (Node*cur = first; cur != NULL; cur=cur->next)
	{
		if (cur->data == data)
		{
			return cur;
		}
	}
	return NULL;
}


void SListPrint(Node *first)
{
	for (Node*cur = first; cur != NULL;cur=cur->next)
	{
		printf("%d ", cur->data);
	}
	printf("\n");
}

void Test()
{
	Node *first;   //没有初始化
	SListInit(&first);
	//期望p==BULL
	SListPushFront(&first, 3);


	//当对空链表尾插时,first还是会改变,所以用地址
	SListPushBack(&first, 2);
	SListPushBack(&first, 7);
	SListPushBack(&first, 2);
	SListPushBack(&first, 2);
	SListPrint(first);

	SListPopBack(&first);
	SListPrint(first);

	Node *p3 = SListFind(first, 2);
	SListInsert(&first, p3,1);
	SListPrint(first);
	SListErase(&first, p3);
	SListPrint(first);
	
}

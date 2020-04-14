#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
typedef int TDataType;

//利用前序序列创建二叉树
//1.单纯用前序序列无法还原二叉树
//2.利用带空结点的前序

//二叉树的结构体   自身结点的数据 和左右结点(同一个类型)
typedef struct BNode{
	TDataType data;
	struct BNode *left;
	struct BNode *right;
}BNode;


//根 用过的结点
typedef struct
{
	BNode *root;
	int used;
}RESULT;




//创建结点 (开房子):
//1.开辟空间 2.放数据 3.指针初始化
static BNode *CreatNode(TDataType data)
{
	BNode *node = (BNode*)malloc(sizeof(BNode));
	node->data = data;
	node->left = node->right = NULL;
}





//利用含空结点的前序创建二叉树
//返回结果是二叉树的根节点
//preorder: 带空结点的前序()
//size: preorder的长度
//难点:1.递归
//     2.创建树的过程中会返回使用过的结点个数
RESULT  CreateTree(TDataType preorder[], int size)
{
	//次数用完 结束
	if (size == 0)
	{
		RESULT result = { NULL, 0 };
		return result;
	}

	//顺序:   根   ,   左子树    ,右子树
	//数组用来保存值
	//判断值是否-1
	TDataType rootValue = preorder[0];
	if(rootValue == -1)
	{
		//如果是-1 返回空指针 和 使用结点个数1
		RESULT result = { NULL, 1 };
		return result;
	}

	//值->创建结点
	BNode *root = CreatNode(rootValue);

	//左用 lr将1值传入,size-1
	RESULT lr = CreateTree(&preorder[1], size - 1);
	root->left = lr.root;
	//右用
	RESULT rr = CreateTree(&preorder[1 + lr.used], size - 1 - lr.used);
	root->right = rr.root;

	
	RESULT result = { root, 1 + lr.used + rr.used };
	return result;
}




/*
 QueueInit  初始化队列
 QueueDestroy 销毁队列

 QueuePush    放队列尾
 QueueFront   查看队首结点
 QueuePop     弹出队首结点
 QueueEmpty   判断队列是否为空
*/

#include"Queue.h"
void LevelOrder(BNode *root)
{
	Queue queue;
	QueueInit(&queue);
	if (root == NULL)
	{
		return;
	}

	QueuePush(&queue,root);
	while (!QueueEmpty(&queue))
	{
		BNode *front = QueueFront(&queue);
		QueuePop(&queue);
		printf("%d ",front->data);

		if (front->left != NULL)
		{
			QueuePush(&queue, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&queue, front->right);
		}
	}

	QueueDestroy(&queue);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include"Stack.h"

void PreorderLoop(BNode *root)
{
	Stack stack;
	StackInit(&stack);
	BNode *node = root;
	BNode*top;

	while (node!=NULL || !StackEmpty(&stack)){
		while (node != NULL)
		{
			printf("%d ", node->data);
			StackPush(&stack, node); //压栈,压的是结点地址
			node = node->left;
		}

		top = StackTop(&stack); StackPop(&stack);
		node = top->right;
	}
}

void InorderLoop(BNode *root)
{
	Stack stack;
	StackInit(&stack);
	BNode *node = root;
	BNode*top;

	while (node != NULL || !StackEmpty(&stack)){
		while (node != NULL)
		{	
			StackPush(&stack, node); //压栈,压的是结点地址
			node = node->left;
		}

		top = StackTop(&stack); StackPop(&stack);
		printf("%d ", top->data);
		node = top->right;
	}
}







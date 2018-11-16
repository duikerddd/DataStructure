
//线性结构
//    顺序存储 顺序表
//    1.静态顺序表
//    1)结构体定义(定义,背后的内存布局模型)
//    2)基本操作
//		初始化+销毁
//      增(头、尾、中)
//      删(头、尾、中)
//        根据数据删除(遇到的第一个和全部)
//		查找


#pragma once   //保证这个文件的宏只被定义1次       这个也是保证定义1次,全文件:#ifndef _xx_ #define _xx_ #endif 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//ADT Abstract Data Type 
typedef int DataType;

#define MAX_SIZE 100

//静态顺序表(顺序表的大小是在静态期间决定的)
//*.c-->可执行文件
//静态事情
//可执行 运行起来
//动态时期
typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;	//1.数组中有效个数的数量  2.下一个可用空间的下标
}SeqListR;

//接口(函数)
// ((接口)函数设计):初始化/销毁
//1.确定是否有返回值
//2.传值  or  传址

void SeqListInit(SeqListR *pSeq)  //用指针: 1.改变值 2.指针内存小
{
	//1.初始化 size
	//2.可能需要去把容器空间清空下
	assert(pSeq != NULL);        //如果没传地址 我也没啥做了

	pSeq->size = 0;
	/*memset(pSep->array, 0, MAX_SIZE*sizeof(DataType));*/  //不全清空是因为可以用size放东西,只需要size为0;如计量器一样
}

void SeqListDestroy(SeqListR *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

// 增
//尾插(尽量和C++的STL统一)
// O(1)    O(1)
void SeqListPushBack(SeqListR *pSeq, DataType data)
{
	assert(pSeq);
	//特殊情况(满了)
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了!\n");
		assert(0); //直接终止程序
		return;
	}

	//通常情况
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//头插(所有人往后走一格,腾出第一个内存给要头插的数)
//    难点:循环的边界
// 1.从后往前搬,否走会覆盖
// 2.循环的区间
//     位置:[size , 0)     for(i=size;i>0;i--)
//     数据:[size-1 , 0]     for(i=size-1;i>=0;i--)
//     O(N)    O(1)
void SeqListPushFront(SeqListR *pSeq, DataType data)
{
	assert(pSeq);
	//特殊情况(满了)
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了!\n");
		assert(0); //直接终止程序
		return;
	}

	//i代表的位置
	for (int i = pSeq->size; i > 0; i--)
	{
		//位置          数据
		pSeq->array[i] = pSeq->array[i - 1];
	}

	//i代表的数据 自己写
	
	//插入
	pSeq->array[0] = data;
	pSeq->size++;


}

//中插   O(N)   O(1)
void SeqListInsert(SeqListR *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//特殊情况(满了)
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了!\n");
		assert(0); //直接终止程序
		return;
	}

	//1.数据搬移(要把后面的数整体搬后一位)
	//从后往前搬   移动方向:->
	//数:[size-1,pos]
	//位置:[size,pos)
	//i是数
	for (int i = pSeq->size-1; i >= pos; i--)
	{
		//位置             数据
		pSeq->array[i+1] = pSeq->array[i];
	}

	//2.插入
	pSeq->array[pos] = data;
	pSeq->size++;
}




//删
//尾删 O(1)   O(1)
void SeqListPushPop(SeqListR *pSeq)
{
	assert(pSeq);

	//特殊情况(空了)
	if (pSeq->size <= 0)
	{
		printf("空了!");
		assert(0);
		return;
	}

	//通常情况
	pSeq->size--;
	
}

//头删(因为是顺序表,删掉最前面,自动往前补)
//画图看就行啦            判断循环的边界,循环的次数  O(N)   O(1)
void SeqListPopFront(SeqListR *pSeq)
{
	assert(pSeq);

	//特殊情况(空了)
	if (pSeq->size <= 0)
	{
		printf("空了!");
		assert(0);
		return;
	}

	//i代表的位置
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		//前位置,后数据
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}

//中删
void SeqListErase(SeqListR *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	//特殊情况(满了)
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了!\n");
		assert(0); //直接终止程序
		return;
	}

	//1.数据搬移(后面的数整体前移)
	//从前往后搬  <-
	//数:(pos,size-1]
	//位置:[pos,size-2]
	//i是数
	for (int i = pos+1; i <= pSeq->size-1; i++)
	{
		//位置              数据
		pSeq->array[i-1] = pSeq->array[i];
	}

	//2.删除
	pSeq->size--;
}





//删除第二种形态(根据数据删除)
//1.删遇到的第一个数据
void SeqListRemove(SeqListR *pSeq, DataType data)
{
	int pos = SeqListFound(pSeq, data);
	if (pos == -1)
	{
		return;
	}
	SeqListErase(pSeq, pos);
}

//2.删除遇到的所有数据
void SeqListRemoveAll(SeqListR *pSeq, DataType data)
{
	//第一种方式 1 1 1 1 1 1...1 1 1
	//时间复杂度:慢 O(n^2)
	//空间复杂度:使用的空间固定 没有根据N的变化申请额外空间 O(1)
	/*while ((pos = SeqListFound(pSeq, data)) != -1)
	{
		SeqListErase(pSeq, pos);
	}*/

#if 0
	//2.一次遍历删除(是真的骚啊)
	//好处:一次遍历 时间比较快
	//坏处:开了新空间,空间大小和size有关系

	//1)开辟一个新的空间[size]
	//2)遍历原来的数组i
	//     if array[i]!=data
	//		new[j++] = array[i++]
	//      else 
	//			i++
	//3)把数据再搬回来
	//4)还剩的数据个数j个

	//时间复杂度: O(n)
	//空间复杂度: O(n)
	DataType *newArray = (DataType *)malloc(sizeof(DataType)*pSeq->size);
	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++)
	{
		if (data != pSeq->array[i])
		{
			newArray[j] = pSeq->array[i];
			j++;
		}
	}
	//把数据搬回来
	for (int i = 0; i < j; i++)
	{
		pSeq->array[i] = newArray[i];
	}
	pSeq->size = j;
	//释放
	free(newArray);

	
#endif
	//第三种方式
	/*
	//时间复杂度:O(n)
	//空间复杂度:O(1)
	 *          
	 */
	int i, j=0;
	for (int i = 0, j = 0; i < pSeq->size; i++)
	{
		if (data != pSeq->array[i])
		{
			pSeq->array[j] = pSeq->array[i];
			j++;
		}
	}
	pSeq->size = j;

}


//查找

//找到第一个遇到的数的下标,没找到返回-1(更理想返回类型 ssize_t)
int SeqListFound(SeqListR *pSeq, DataType data)
{
	//二分查找(前提是有序)
	//顺序遍历查找
	for (int i = 0; i < pSeq->size; i++)
	{
		if (data == pSeq->array[i])
		{
			//找到返回下标
			return i;
		}
	}
	return -1;
}

//查看属性
bool SeqListEmpty(const SeqListR *pSeq)
{
	return pSeq->size == 0;
}

bool SeqListFull(const SeqListR *pSeq)
{
	return pSeq->size == MAX_SIZE;
}

int SeqListSize(const SeqListR *pSeq)
{
	return pSeq->size;
}


void Swap(DataType *a, DataType *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//冒泡排序
void BubbleSort(SeqListR *pSeq)
{
	//i表示要放最大的数[size-1,1]
	//j表示要比较的数[0,i)
	int i, j;
	bool sorted = true;
	for (int i = pSeq->size - 1; i > 0; i--)
	{
		sorted = true;//假设有序
		for (int j = 0; j < i; j++)
		{
			if (pSeq->array[i] > pSeq->array[j])
			{
				//没找到更大的
				Swap(pSeq->array+i, pSeq->array+j);
				sorted = false;
			}
		}
	//一次冒泡过程中,一次交换都没有,所以已经有序了
	if (sorted)
		{
		break;
		}
	}
	

}
//选择排序
//    选择  (每次选(最大),放到最后)
//     5   3   2   6   9   8   7   1  0
//                     -              找到最大,交换 界限减1
//      5   3   2   6   8   7   1  0   不看9 继续交换 界限减1
//      最后一次    1 0 2 3 5 7 8  9    交换 界限减1
//    选择排序进阶版(每次过程中选出最大和最小)
typedef unsigned int size_t;

void SelectSortOP(SeqListR *pSeq)
{
	size_t minSpace = 0;
	size_t maxSpace = pSeq->size - 1;

	//区间剩一个数 或者 零个数
	while (minSpace < maxSpace)
	{
		size_t minPos = minSpace;//假设第一个就是最小的
		size_t maxPos = minSpace;//假设第一个就是最大的
		for (int j = minSpace; j <= maxSpace; j++)
		{
			if (pSeq->array[j] < pSeq->array[minPos])
			{
				minPos = j;
			}
			if (pSeq->array[j] > pSeq->array[maxPos])
			{
				maxPos = j;
			}
		}
		Swap(pSeq->array + minSpace, pSeq->array + minPos);
		//最大的数就是第一个的时候
		if (minSpace == maxPos)
		{
			maxPos = minPos;
		}
		Swap(pSeq->array + maxSpace, pSeq->array + maxPos);

		minSpace++;
		maxSpace--;
	}
}


//打印数字
void SeqListPrint(const SeqListR *pSeq)
{
	assert(pSeq != NULL);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}

void Test()
{
	SeqListR seqList;
	SeqListInit(&seqList);

	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 9);
	SeqListPrint(&seqList);
	
	SelectSortOP(&seqList);

	SeqListPrint(&seqList);
}


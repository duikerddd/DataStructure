#pragma once

#include<stdio.h>


//快排最快情况：每次排到中间 O(N * logN)
//快排最慢情况：每次只排好一个值 O(N^2)
void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//优化:三数取中
int GetMidIndex(int *a,int begin,int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin]>a[end])
			return begin;
		else
			return end;
		
	}
	else //begin>mid
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}


//左右指针
int PartSort(int *a,int begin,int end)
{
	//三数取中 让高度更均匀
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int key = begin;
	while (begin < end)
	{
		//end找小  找不到继续向左走 begin《end是为防止两个指针错开或越界
		while (begin<end && a[end] >= a[key])
		{
			--end;
		}
		//begin找大
		while (begin<end && a[begin] <= a[key])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[begin]);
	return end;
}


//挖坑法:
int PartSortWakeng(int *a, int begin, int end)
{
	//挖坑,坑值为要分割的值,与坑值比较
	int tmp = a[begin];
	while (begin<end)
	{
		//end找小 
		while (begin < end && a[end] >= tmp)
		{
			--end;
		}
		//填左坑
		a[begin] = a[end];

		//bigin找大 
		while (begin<end && a[begin] <= tmp)
		{
			++begin;
		}
		//填右坑
		a[end] = a[begin];
	}
	//最后坑的值
	a[begin] = tmp;
	return tmp;
	
	
}

//前后指针
void PartSortZhizhen(int *a, int begin, int end)
{
	int key = begin;
	int prev = begin;
	int cur = begin + 1;
	//指针开始一前一后挨着
	while (cur <= end)
	{ 
		//cur先走,找小,找到后与pre后的指针交换(因为cur没有停下就说明走过的数肯定比key大)
		if (a[cur] < a[key] && ++prev!=cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	//最后将pre的指针和key交换位置
	Swap(&a[begin], &a[prev]);
	return  prev;
}

//整体：每次切一下，两端继续切，切分成节点 
//局部：左右指针移动，交换
void QuickSort(int *a, int left,int right)
{
	//区间交错直接返回
	if (left >= right)
	{
		return;
	}
		
	//最后几层递归太多 , 数据少的时候用其他方式更好一点
	//[left,div-1] [div+1,rihgt]
	if (right - left > 10)
	{
		int div = PartSort(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		//插入排序
	}

}

//非递归 借助栈
//压区间 
void QuickSortNonR(int *a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (StackEmpty(&st)!=0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int div = PartSort(a, begin, end);

		//[begin,div-1]
		if (begin < div - 1)
		{
			StackPush(&st,div - 1);
			StackPush(&st,begin);
		}

		//[div+1,end]
		if (div+1<end)
		{
			StackPush(&st,end);
			StackPush(&st,div+1);
		}
	}
} 

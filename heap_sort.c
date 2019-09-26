#pragma once

#include<stdio.h>

void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//无左子树 空树 返回0
//左子树 返回
//左右子树 返回min

void AdjustDown(int *a, int n, int root)
{
		int parent = root;
		int child = parent * 2 + 1;
		while (child < n)
		{
			//让child指向大孩子
			if (child + 1 < n && a[child + 1] > a[child])
			{
				++child;
			}
			if (a[child]>a[parent])
			{
				Swap(&a[child], &a[parent]);
				//更新孩子父母
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{ 
				break;
			}
		}
}

//a[0]=min
void HeapSort(int *a,int n)
{
	//建堆
	//从倒数第一个非叶子结点开始
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a,n,i);
	}

	//调堆
	//将a[0]和倒数end的结点交换,开始向下调整排序,相当于把全部的结点都放在a[0]上向下调整
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0],& a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

	
}

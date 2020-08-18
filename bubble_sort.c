#pragma once

#include<stdio.h>

void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void BubbleSort(int *a, int n)
{
	//外层控制单趟排序
	for (int end = n; end > 0; --end){
		int exchange = 0;


		//单趟排序
		for (int i = 0; i < n - 1; ++i)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				 exchange=1;
			}
		}
		//如果没交换 说明有序
		if (exchange == 0)
		{
			break;
		}
	}
}


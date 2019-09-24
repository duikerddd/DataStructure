#pragma once
#include<stdio.h>

//选择排序: 优点:好理解...实际很少使用
void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//在[begin,end]之间选max min 直到区间没有数字
void SelectSort(int *a, int n)
{
	int begin = 0,  end = n - 1;
	while (begin < end){

		int min=begin, max=begin;

		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
		//max在begin位置 被交换
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}

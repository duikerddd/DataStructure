#pragma once

#include<stdio.h>

//希尔排序: 1.预排序(接近有序) 2.插入排序
//gap为1的时候就是插入排序
void ShellSort(int *a, int n)
{
	int gap = n;//gap越小 越有序
	while (gap > 1)
	{
		gap = gap / 3 + 1;//保证gap最少为1
		//预处理 
		for (int i = 0; i< n - gap; ++i){
			int end = i;
			int tmp = a[end + gap];

			while (end >= 0 && a[end] > tmp)
			{
				a[end+gap] = a[end];
				end -= gap;
			}

			a[end + gap] = tmp;
		}
	}
}

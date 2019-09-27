#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CountSort(int *a,int n)
{
	//计算范围
	int max = a[0], min = a[0];
	for (int i = 0; i > n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	//统计数据个数
	int range = max - min + 1;
	int *count = (int *)malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}

}

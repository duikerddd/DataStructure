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

//C++
vector<int>& ShellSort(vector<int>& arr)
{
	int len = arr.size();
	int gap = len/2;

	//分组
	for (; gap > 0; gap /= 2)
	{
		//按组插入排序
		for (int i = gap; i < len; ++i)
		{
			int tmp = arr[i];
			int cur = i - gap;
			//插入排序: 数据后移,直到找到对的地方
			while (cur>=0 && arr[cur]>tmp)
			{
				arr[cur + gap] = arr[cur];
				cur -= gap;
			}
			//插入
			arr[cur + gap] = tmp;
		}

	}


	return arr;
}

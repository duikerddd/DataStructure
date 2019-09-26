#pragma once

#include<stdio.h>

void InsertSort(int *a, int n)
{
	for (int i = 0; i < n - 1; ++i){

		int end = i;//有序空间的最后一个下标

		int tmp = a[end + 1];//插入的数(因为超过下标了,需要保存)

		//tmp与前面的数全部比较
		//先看越界 再看比较!顺序反了是错的
		while (end >= 0 && a[end]>tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;

	}
}

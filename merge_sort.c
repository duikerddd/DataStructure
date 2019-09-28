#pragma once

#include<stdio.h>
#include<stdlib.h>

//归并排序: 回溯法解决问题 先分解成最小子问题,再开始合并子问题的解
void _MergeSort(int* a,int begin,int end,int* tmp)
{
	if (begin >= end)
		return;

	int mid = begin + ((end - begin) >> 1);

	//子问题:[begin,mid-1] [mid,end]排序
	_MergeSort(a, begin, mid - 1, tmp);
	_MergeSort(a, mid, end, tmp);

	//归并[begin,mid-1] [mid,end]
	int begin1 = begin, end1 = mid - 1;
	int begin2 = mid, end2 = end;
	int index = begin;

	//按大小把两个数组排序
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])

			tmp[index++] = a[begin1++];
		else

			tmp[index++] = a[begin2++];
	}
	//把剩下的全拷后面
	while (begin1<end1)
		tmp[index++] = a[begin1++];
	while (begin2<end2)
		tmp[index++] = a[begin2++];

	//归并结果拷回原数组
	index = begin;
	while (begin <= end)
	{
		a[index++] = a[begin++];
	}
} 

void MergeSort(int *a, int n)
{
	int* tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);

}

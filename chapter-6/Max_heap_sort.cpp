/*
 * Filename: Max_heap_sort.cpp 
 * 
 * 堆排序是利用堆的数据结构进行排序的一种算法
 * 时间复杂度为O(nlogn)
 * 空间复杂度为O(1)
 * 
 * 堆排序的特点：
 * １．最好的时间复杂度和最坏的时间复杂度都是O(nlogn)
 * ２．主要用于优先队列，在大规模数据排序主要用快排
 * ３．不是稳定排序
 * 
 * 
 */

#include <algorithm>
#include <iostream>
using namespace std;

void max_heapify(int arr[], int heap_sz, int i)
{
	int left = 2*i+1, right = 2*i+2, index = i;
	if (left < heap_sz && arr[index] < arr[left])
		index = left;
	if (right < heap_sz && arr[index] < arr[right])
		index = right;
	if (i != index)
	{
		swap(arr[i], arr[index]);
		max_heapify(arr, heap_sz, index);
	}
}

void build_max_heap(int arr[], int heap_sz)
{
	int p =  (heap_sz - 2) / 2;
	while (p >= 0)
		max_heapify(arr, heap_sz, p--);
}

void max_heap_sort(int arr[], int heap_sz)
{
	build_max_heap(arr, heap_sz);
	while (heap_sz > 1)
	{
		swap(arr[0], arr[heap_sz - 1]);
		max_heapify(arr, --heap_sz, 0);
	}
}

int main()
{
	int sz = 10, arr[sz] = {5, 10, 1, 6, 2, 9, 3, 8, 7, 4};
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	max_heap_sort(arr, sz);
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	return 0;
}















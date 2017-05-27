/**
 * Filename: Min_heap_sort.cpp
 * 
 * 最小堆排序算法（排序后为降序），与最大堆排序（排序后为升序）相似
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;

void min_heapify(int arr[], int heap_sz, int i)
{
	int left = 2*i+1, right = 2*i+2, index = i;
	if (left < heap_sz && arr[left] < arr[index])
		index = left;
	if (right < heap_sz && arr[right] < arr[index])
		index = right;
	if (i != index)
	{
		swap(arr[i], arr[index]);
		min_heapify(arr, heap_sz, index);
	}
}

void build_min_heap(int arr[], int heap_sz)
{
	int p = (heap_sz - 2) / 2;
	while (p >= 0)
		min_heapify(arr, heap_sz, p--);
}

void min_heap_sort(int arr[], int heap_sz)   //arr[0...heap_sz-1] 为无序数组
{
	build_min_heap(arr, heap_sz);
	while (heap_sz > 1)
	{
		swap(arr[0], arr[heap_sz - 1]);
		min_heapify(arr, --heap_sz, 0);
	}
}

int main()
{
	int sz = 10, arr[sz] = {4, 10, 1, 5, 9, 2, 6, 8, 7, 3};
	for (int i = 0; i < sz; ++i)  cout << arr[i] << " "; cout << endl;
	min_heap_sort(arr, sz);
	for (int i = 0; i < sz; ++i)  cout << arr[i] << " "; cout << endl;
	return 0;
}










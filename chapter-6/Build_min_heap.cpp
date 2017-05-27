/*
 * Filename: Build_min_heap.cpp 
 * 
 * 构建最小堆算法
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
	{
		min_heapify(arr, heap_sz, p);
		p--;
	}
}

int main()
{
	int sz = 9, arr[sz] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	build_min_heap(arr, sz);
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	return 0;
}



/*
 * Filename: 6.5-8.cpp
 * 
 * 在O(logn)的时间复杂度内实现heap_delete操作
 * 
 * 
 */

#include <algorithm>
#include <iostream>
using namespace std;

void max_heapify(int arr[], int heap_sz, int i)
{
	int left = 2*i+1, right = 2*i+2, index = i;
	if (left < heap_sz && arr[left] > arr[index])
		index = left;
	if (right < heap_sz && arr[right] > arr[index])
		index = right;
	if (i != index)
	{
		swap(arr[index], arr[i]);
		max_heapify(arr, heap_sz, index);
	}
}

void build_max_heap(int arr[], int heap_sz)
{
	int p = (heap_sz-2)/2;
	while (p >= 0)
	{
		max_heapify(arr, heap_sz, p);
		--p;
	}
}

void heap_delete(int arr[], int& heap_sz, int i)
{
	swap(arr[heap_sz-1], arr[i]);
	--heap_sz;
	int p = (i-1)/2, l = 2*i+1, r = 2*i+2; 
	while (p >= 0 && arr[i] > arr[p])
	{
		swap(arr[i], arr[p]);
		i = p;
		p = (i-1)/2;
	}
	max_heapify(arr, heap_sz, i);
}

int main()
{
	int sz = 10, arr[sz] = {5, 3, 9, 10, 8, 1, 6, 7, 2, 4};
	for (int i = 0; i < sz; ++i)  cout << arr[i] << " "; cout << endl;
	build_max_heap(arr, sz);
	for (int i = 0; i < sz; ++i)  cout << arr[i] << " "; cout << endl;
	heap_delete(arr, sz, 3);
	for (int i = 0; i < sz; ++i)  cout << arr[i] << " "; cout << endl;
	return 0;
}









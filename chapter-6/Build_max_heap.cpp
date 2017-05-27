/*
 * Filename: Build_max_heap.cpp 
 * 
 * 构建最大堆
 * 
 * 
 */

#include<iostream>
#include<algorithm>
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
	int p = (heap_sz - 2) / 2;
	while (p >= 0)
	{
		max_heapify(arr, heap_sz, p);
		p--;
	}
}

int main()
{
	int sz = 9, arr[sz] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i = 0; i < sz; ++i)  cout << arr[i] << " "; cout << endl;
	build_max_heap(arr, sz);
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	return 0;
}





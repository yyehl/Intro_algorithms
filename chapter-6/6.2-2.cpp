/*
 * Filename: 6.2-2.cpp 
 * 
 * 题目：写出最小堆 min_heapify 的代码
 * 
 * min_heapify 和 max_heapify 的运行时间是一致的
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

void min_heapify(int arr[], int heap_sz, int i)
{
	int left = 2*i+1, right = 2*i+2, min_index = i;
	if (left < heap_sz && arr[left] < arr[min_index])
		min_index = left;
	if (right < heap_sz && arr[right] < arr[min_index])
		min_index = right;
	if (i != min_index)
	{
		swap(arr[i], arr[min_index]);
		min_heapify(arr, heap_sz, min_index);
	}
}

int main()
{
	int sz = 3, arr[3] = {3, 2, 1};
	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	min_heapify(arr, sz, 0);
	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	return 0;
}






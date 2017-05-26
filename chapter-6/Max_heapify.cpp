/*
 * Filename: Max_heapify.cpp 
 * 
 * 最大堆的核心程序，维护某一节点的堆序性质，又称“下溯”
 * 
 * 
 */

#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void max_heapify(int arr[], int heap_sz, int i)       
{
	int max_index = i, left = 2*i+1, right = 2*i+2;
	if (left < heap_sz && arr[max_index] < arr[left])
		max_index = left;
	if (right < heap_sz && arr[max_index] < arr[right])
		max_index = right;
	if (i != max_index)
	{
		swap(arr[i], arr[max_index]);
		max_heapify(arr, heap_sz, max_index);
	}
}

int main()
{
	int sz = 3, arr[sz] = {1, 2, 3};
	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	max_heapify(arr, sz, 0);
	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	return 0;
}







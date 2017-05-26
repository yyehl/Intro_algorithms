/*
 * Filename: 6.2-5.cpp 
 * 
 * 题目：用循环代替递归重写max_heapify
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int arr[], int heap_sz, int i)
{
	int index, left = 2*i+1, right = 2*i+2;
	while (left < heap_sz)
	{
		if (right < heap_sz && arr[left] < arr[right])
			index = right;
		else
			index = left;
		if (arr[i] < arr[index])
		{
			swap(arr[i], arr[index]);
			i = index;
			left = 2*i+1;
			right = 2*i+2;
		}
		else
			break;
	}
}

int main()
{
	int sz = 6, arr[sz] = {1, 2, 3, 4, 5, 6};
	for (int i = 0; i < sz; i++) cout << arr[i] << " ";
	cout << endl;
	max_heapify(arr, sz, 0);
	for (int i = 0; i < sz; i++) cout << arr[i] << " ";
	cout << endl;
	return 0;
}






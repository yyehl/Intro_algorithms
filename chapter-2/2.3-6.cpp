/*
 * Filename: 2.3-6.cpp 
 * 
 * 题目：将插入排序中反向查找已排序序列部分用二分查找改写，将复杂度降为O(nlogn)
 * 
 * 
 */

#include <iostream>
using namespace std;

/* 插入排序原版 */
void insertion_sort(int arr[], int sz)
{
	if (sz <= 1) return;
	for (int i = 1; i < sz; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

/* 二分优化版本 */
void insertion_sort_optimize(int arr[], int sz)
{
	if (sz <= 1) return;
	for (int i = 1; i < sz; ++i)
	{
		int key = arr[i];
		int left = 0, right = i - 1;  // search range [left, right]
		while (left <= right)
		{									
			int mid = (left + right) / 2;    
			if (arr[mid] <= key)
				left = mid + 1;     // <= 保证了排序的稳定性，循环结束后，left即为key要插入的位置
			else
				right = mid - 1;
		}
		for (int j = i - 1; j >= left; --j)  // 将[left, i - 1]的元素copy到[left + 1, i]
			arr[j + 1] = arr[j];
		
		arr[left] = key;
	}
}

int main()
{
	int arr[10] = {5, 1, 0, 9, 4, 2, 6, 6, 3, 8};

	cout << "prim: " ;
	for (int i = 0; i < 10; ++i) cout << arr[i] << " ";
	cout << endl;
	
	insertion_sort(arr, 10);
	cout << "sort: ";
	for (int i = 0; i < 10; ++i) cout << arr[i] << " ";
	cout << endl;
	
	insertion_sort_optimize(arr, 10);
	cout << "s_op: ";
	for (int i = 0; i < 10; ++i) cout << arr[i] << " ";
	cout << endl;
	return 0;
}









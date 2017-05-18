/*
 * Filename: 2.3-1.cpp 
 * 
 * 题目：说明归并排序在数组A = {3, 41, 52, 26, 38, 57, 9, 49}上的操作
 * 
 */



#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) // arr[low, mid] and arr[mid + 1, high] are sorted
{
	int* tmp = new int[high - low + 1];
	int left = low, right = mid + 1, index = 0;
	while (left <= mid && right <= high)
	{
		if (arr[left] <= arr[right])  // <= 保证了稳定排序
		{
			tmp[index] = arr[left];
			++left;
		}
		else
		{
			tmp[index] = arr[right];
			++right;
		}
		++index;
	}
	while (left <= mid)
	{
		tmp[index] = arr[left];
		++left;
		++index;
	}
	while (right <= high)
	{
		tmp[index] = arr[right];
		++right;
		++index;
	}
	for (int i = 0; i < index; ++i, ++low)  // 注意边界条件 i < index 和 ++low
		arr[low] = tmp[i];

	delete [] tmp;  // 千万不能忘记
}

void merge_sort(int A[], int low, int high)  // A[low, high]
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(A, low, mid);
		merge_sort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}

int main()
{
	int A[8] = {3, 41, 52, 26, 38, 57, 9, 49};
	cout << "原　序　列：";
	for (int i = 0; i < 8; ++i)  cout << A[i] << " ";
	cout << endl;
	merge_sort(A, 0, 7);
	cout << "排序后序列：";
	for (int i = 0; i < 8; ++i)  cout << A[i] << " ";
	cout << endl;
	return 0;
}














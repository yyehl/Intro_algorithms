/*
 * Filename: 2-1.cpp 
 * 
 * 题目：在归并排序中对小数组用插入排序
 * 
 * 分析：在多小的小数组时采用插入排序呢？
 * 　　　归并排序的最坏时间复杂度和平均时间复杂度都是 nlogn
 *       插入排序的最坏时间复杂度为 n(n-1)/2, 平均时间复杂度为 n(n-1)/4
 * 　　　所以另　nlogn = n(n-1)/2  -- <1>
 *               nlogn = n(n-1)/4  -- <2>
 * 		 
 * 		 n大约在6~18之间，插入排序和归并排序可以说效率几乎相等，
 * 		 n大于这个范围应该用归并排序，小于这个范围应该用插入排序
 * 　　　
 *　　   此次取n = 10
 */

#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) // arr[low, mid] and arr[mid + 1, high] are sorted
{
	int* tmp = new int[high - low + 1];
	int left = low, right = mid + 1, index = 0;
	while (left <= mid && right <= high)
	{
		if (arr[left] <= arr[right])
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
		++index;
		++right;
	}
	for (int i = 0; i < index; ++i, ++low)  // dont forget ++low
		arr[low] = tmp[i];                  // 注意是tmp[i]  不是tmp[index]

	delete [] tmp;
}

void insertion_sort(int arr[], int low, int high)  // [low, high]
{
	if (high - low < 1) return;
	for (int i = low + 1; i <= high; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= low && key < arr[j])
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void merge_and_insert_sort(int arr[], int low, int high)  // [low, high]
{
	if (high - low >= 10)                                 //　当元素个数大于10的时候，用归并排序
	{
		int mid = (low + high) / 2;
		merge_and_insert_sort(arr, low, mid);
		merge_and_insert_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
	else                                                  //  当元素个数小于等于10的时候，用插入排序
	{
		insertion_sort(arr, low, high);
	}
}

int main()
{
	int arr[20] = {1,9,20,5,7,13,19,15,14,3,17,16,2,11,8,4,18,12,10,6};
	cout << "prim: ";
	for (int i = 0; i < 20; ++i) cout << arr[i] << " ";  cout << endl;

	merge_and_insert_sort(arr, 0, 19);
	cout << "mais: ";
	for (int i = 0; i < 20; ++i) cout << arr[i] << " "; cout << endl;
	return 0;
}

















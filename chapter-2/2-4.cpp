/*
 * Filename: 2-4.cpp 
 * 
 * 逆序对：数组A中，当i < j时，A[i] > A[j]，则称A[i], A[j]为一对逆序对	
 * 
 * 题目：给出一个在n个元素的任何排列中逆序对数量的算法，O(nlogn)。（提示：修改归并排序）
 * 
 */

#include <iostream>
using namespace std;

// O(n^2)版本

int inversion_count1(int arr[], int sz)
{
	int count = 0;
	for (int i = 0; i < sz; ++i)
	{
		for (int j = i + 1; j < sz; ++j)
		{
			if (arr[j] < arr[i])
				++count;
		}
	}
	return count;
}

/*******************************************************/

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// 关键思想：与归并排序同步进行，因为左右两个子序列是已排序的
// 　　　　　所以当arr[left] > arr[right]时, arr[left+1....mid] > arr[right]均成立，所以此时count += mid - left + 1 

int merge_count(int arr[], int low, int mid, int high)
{
	int* tmp = new int[high - low + 1];
	int left = low, right = mid + 1, index = 0, count = 0;
	while (left <= mid && right <= high)
	{
		if (arr[left] <= arr[right])
		{
			tmp[index] = arr[left];
			++left;
		}
		else         // arr[left] > arr[right],  is inversion
		{
			tmp[index] = arr[right];
			++right;
			count += mid - left + 1;
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
	for (int i = 0; i < index; ++i, ++low)
		arr[low] = tmp[i];

	delete [] tmp;
	return count;
}

int inversion_count2(int arr[], int low, int high)  // arr[low, high]
{
	int lc = 0, rc = 0, mc = 0;
	if (low < high)
	{
		int mid = (low + high) / 2;
		lc = inversion_count2(arr, low, mid);
		rc = inversion_count2(arr, mid + 1, high);
		mc = merge_count(arr, low, mid, high);
	}
	return lc + rc + mc;
}

int main()
{
	int arr[5] = {2, 3, 8, 6, 1};
	cout << "inversion count1: " << inversion_count1(arr, 5) << endl;
	cout << "inversion count2: " << inversion_count2(arr, 0, 4) << endl;
	return 0;
}

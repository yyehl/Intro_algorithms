/*
 * Filename: 15.4-6.cpp 
 * 
 * O(nlogn)的最长递增子序列问题
 * 
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

int binary_search(int arr[], int left, int right, int val)
{
	int low = left, high = right, mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] < val)  low = mid + 1;
		else if (arr[mid] > val) high = mid - 1;
		else return mid;
	}
	return low;
}

int longestIncreaseSubarray(int arr[], int n)
{
	int L[n], len = 1;   // L[i] 表示长度为i的最长递增子序列的最小末尾元素，len记录最大的递增子序列长度
	L[0] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		int left = binary_search(L, 0, len-1, arr[i]);
		L[left] = arr[i];
		if (left > len-1) len++;
	}
	return len;
}

int main()
{
	//int s1 = 10, arr1[s1] = {1,5,8,0,4,7,10,11,5,7};
	int s2 = 8, arr2[s2] = {1,7,8,2,3,4,5,6};

	//cout << longestIncreaseSubarray(arr1, s1) << endl;
	cout << longestIncreaseSubarray(arr2, s2) << endl;
	return 0;
}




















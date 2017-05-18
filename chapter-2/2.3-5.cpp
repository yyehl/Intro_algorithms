/*
 * Filename: 2.3-5.cpp 
 * 
 * 题目：二分查找
 * 
 */

#include <iostream>
using namespace std;

int binary_search(int arr[], int sz, int key)
{
	int left = 0, right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return -1;  // 执行到这里就说明没有与key值相等的元素
}

int main()
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "元素1的位置应为1, 输出：" << binary_search(arr, 10, 1) << endl;
	cout << "元素5的位置应为5, 输出：" << binary_search(arr, 10, 5) << endl;
	cout << "元素11不在arr中，输出应为-1, 输出：" << binary_search(arr, 10, 11) << endl;
	return 0;
}









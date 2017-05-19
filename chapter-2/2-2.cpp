/*
 * Filename: 2-2.cpp
 * 
 * 题目：冒泡排序
 * 
 * 冒泡排序基本思想：从左到右遍历数组，将待排序的序列从右到左遍历，如果相邻元素顺序相反，则交换这两个元素，直到没有要交换的元素为止
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 
 * 冒泡排序特点：
 * 	   1. 最好情况为已排序情况，时间复杂度为O(n^2), 优化后为O(n)
 *     2. 最坏情况为反序，复杂度为O(n^2)
 *     3. 优点为思想简单，容易实现
 *     4. 缺点为低效率
 */

#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


void bubble_sort(int arr[], int sz)
{
	if (sz <= 1) return;
	for (int i = 0; i < sz - 1; ++i)
	{
		for (int j = sz - 1; j > i; --j)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

void bubble_sort_optimize(int arr[], int sz)
{
	if (sz <= 1) return;
	for (int i = 0; i < sz - 1; ++i)
	{
		bool flag = false;
		for (int j = sz - 1; j > i; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = true;
			}
		}
		if (flag == false) return;
	}
}

int main()
{
	int arr[10] = {5, 8, 9, 1, 0, 3, 7, 2, 4, 6};
	cout << "prim: ";
	for (int i = 0; i < 10; ++i) cout << arr[i] << " "; cout << endl;

	bubble_sort(arr, 10);
	cout << "bbst: ";
	for (int i = 0; i < 10; ++i) cout << arr[i] << " "; cout << endl;

	int arr1[10] = {5, 8, 9, 1, 0, 3, 7, 2, 4, 6};
	cout << "prim: ";
	for (int i = 0; i < 10; ++i) cout << arr1[i] << " "; cout << endl;

	bubble_sort_optimize(arr1, 10);
	cout << "prim: ";
	for (int i = 0; i < 10; ++i) cout << arr1[i] << " "; cout << endl;

	return 0;
}



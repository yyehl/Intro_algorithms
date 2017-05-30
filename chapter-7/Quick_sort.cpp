/*
 * Filename: Quick_sort.cpp 
 * 
 * 快速排序是最重要的，运用最广泛的一种排序算法。
 * 快排的基本思想：先选定一个数p，然后从左右两边同时遍历序列，若左边出现大于p的元素，右边出现小于p的元素，则交换左右元素
 *　　　　　　　　 将序列分为两个子序列，保证序列左边的元素小于等于p，序列右边的元素大于等于p
 *				   在递归调用两个子序列，执行同样的操作，直至排序完成
 * 
 * 时间复杂度：最坏情况为O(n^2)，平均情况为O(nlogn)
 * 空间复杂度：O(1)
 * 
 * 快速排序的特点：
 * 　１．在随机数据中排序速度最快，
 * 　２．尽管最坏时间复杂度为O(n^2)，但是很难达到
 * 　３．轴承元素的选取有多种方法
 * 　４．在几近排序状态的序列排序中，快排的效率一般不如插入排序高
 *   ５．快排是不稳定排序
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

void quick_sort(int arr[], int left, int right)   // [left, right]
{
	if (left < right)
	{
		int l = left, r = right-1, p = arr[right];
		while (true)
		{
			while (arr[l] < p)
				++l;
			while (arr[r] > p && r > left)
				--r;
			if (l < r)
			{
				swap(arr[l], arr[r]);
				++l;
				--r;
			}
			else
				break;
		}
		swap(arr[right], arr[l]);
		quick_sort(arr, left, l-1);
		quick_sort(arr, l+1, right);
	}
}

int main()
{
	int sz = 10, arr[sz] = {6, 0, 0, 0, 1111, 2222, 4, 0, 2, 1};
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	quick_sort(arr, 0, sz-1);
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	return 0;
}

























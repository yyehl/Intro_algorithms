/*
 * Filename: 2.2-2.cpp 
 * 
 * 题目：选择排序
 * 
 * 
 * 选择排序：n个元素，经过n-1次循环，每次选出待排序序列中最小（大）元素与已排序序列的后一位元素交换
 * 			从左到右遍历序列，将最小（大）元素选出来与第一个位置元素交换，次小（大）元素选出来与第二个位置的元素交换，以此类推。。
 * 选择排序时间复杂度：O(n^2)			　
 * 选择排序空间复杂度：O(1)
 * 
 * 选择排序的特点：
 * 			1. 优点是思想简单，容易实现
 * 			2. 缺点是对于大数据集效率不高
 * 			3. 每次循环最多交换一次数据，n个数据完成排序最多交换n-1次数据，相对不错
 * 			4. 不是稳定排序
 * 
 */


#include <vector>
#include <iostream>
using namespace std;

void swap(int& i, int& j)
{
	int tmp = i;
	i = j;
	j = tmp;
}

void selection_sort(vector<int>& iv)
{
	if (iv.size() == 0 || iv.size() == 1) return;
	for (int i = 0; i < iv.size(); ++i)
	{
		int min = iv[i], min_index = i;
		for (int j = i + 1; j < iv.size(); ++j)
		{
			if (iv[j] < min)
			{
				min = iv[j];
				min_index = j;
			}
		}
		if (min_index != i)
			swap(iv[min_index], iv[i]);
	}
}

int main()
{
	vector<int> v = {5, 2, 9, 10, 6, 1, 8, 3, 7, 0, 4};
	cout << "原　序　列：";
	for (auto i : v) cout << i << " ";
	cout << endl;
	selection_sort(v);
	cout << "排序后序列：";
	for (auto i : v) cout << i << " ";
	cout << endl;
	return 0;
}














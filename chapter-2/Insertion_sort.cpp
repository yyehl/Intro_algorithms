/*
* Filename: Insertion_sort.cpp
* 
* 插入排序基本思想：
* 　　遍历整个序列，保证已经遍历了的序列有序，然后在每一步将元素插入到合适的位置，保证其仍然有序　　
*	　比如，遍历到i处，则将i元素从右往左与[0, i-1]的元素进行比较，将i插入合适的位置，保证其仍然有序。
* 插入排序的时间复杂度：O(n^2)
* 插入排序的空间复杂度：O(1)
* 插入排序的特点：
* 	　1. 插入排序最好的情况是序列已经有序，此时只需要执行n-1次比较，无需移动数据
*	　2. 插入排序最坏的情况是序列反序，此时需要执行n(n-1)/2次比较，执行n(n+1)/2 - 1次的数据移动
*	　3. 插入排序是稳定排序，即排序前后相等元素的相对位置不改变
*	　4. 插入排序对小数据集有效，对已近排序状态序列具有较高的效率
**/


#include <vector>
#include <iostream>
using namespace std;

void insertion_sort(vector<int>& iv)
{
	if (iv.size() == 1 || iv.size() == 0) return;
	for (int i = 1; i < iv.size(); ++i)
	{
		int key = iv[i];
		int j = i - 1;
		while (j >= 0 && key < iv[j])
		{
			iv[j + 1] = iv[j];
			--j;
		}
		iv[j + 1] = key;
	}
}

int main()
{
	vector<int> v = {5, 9, 1, 4, 10, 2, 8, 3, 7, 6, 0};
	cout << "原  序  列: ";
	for (auto i : v) cout << i << " ";
	cout << endl;
	insertion_sort(v);
	cout << "排序后序列: ";
	for (auto i: v) cout << i << " ";
	cout << endl;
	return 0;
}




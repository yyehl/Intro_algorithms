/*
 * Filename: 4.1-2.cpp 
 * 
 * 题目：最大子数组的O(n^2)的暴力解法
 * 
 **/

#include <iostream>
using namespace std;

void find_max_subarray(int arr[], int sz, int* ret)
{
	int left, right, max = -10000;
	for (int i = 0; i < sz; ++i)
	{
		int num = 0;
		for (int j = i; j < sz; ++j)
		{
			num += arr[j];
			if (num > max)
			{
				left = i;
				right = j;
				max = num;
			}
		}
	}
	ret[0] = left; ret[1] = right; ret[2] = max;
}

int main()
{
	int sz = 16;
	int arr[sz] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int ret[3] = {0, 0, 0};

	find_max_subarray(arr, sz, ret);
	cout << ret[0] << " " << ret[1] << " " <<  ret[2] << endl;
	return 0;
}

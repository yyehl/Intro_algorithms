/**
 * Filename: 4.1-5.cpp
 * 
 * 题目：线性时间O(n)的最大子数组算法，基于动态规划
 * 
 **/

#include <iostream>
using namespace std;

void find_max_subarray(int arr[], int sz, int* ret)
{
	int left, right, sum = 0, max = -10000;
	for (int i = 0; i < sz; ++i)
	{
		if (sum > 0)
		{
			sum += arr[i];
			if (sum > max)
			{
				max = sum;
				right = i;
			}
		}
		else
		{
			sum = arr[i];
			left = i;
		}
	}
	ret[0] = left; ret[1] = right; ret[2] = max;
}

int main()
{	
	int sz = 16;
	int arr[sz] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int ret[3];
	find_max_subarray(arr, sz, ret);
	cout << ret[0] << " " << ret[1] << " " << ret[2] << endl;
	return 0;
}






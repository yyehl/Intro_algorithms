/*
 * Filename: 15.4-5.cpp 
 * 
 * O(n^2)算法计算数组的最长递增子序列
 * 
 */


#include <stdlib.h>
#include <iostream>
using namespace std;

int find_max_increase_subarray(int arr[], int n)
{
	int c[n], b[n];
	c[0] = 1, b[0] = arr[0];

	for (int i = 1; i < n; ++i)
	{
		int c_tmp = 0;
		int b_tmp;
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > b[j])
			{
				if (c_tmp < c[j] + 1)
				{
					c_tmp = c[j] + 1;
					b_tmp = arr[i];
				}
			}
			else 
			{
				if (c_tmp < c[j])
				{
					c_tmp = c[j];
					b_tmp = b[j];
				}
			}
		}
		c[i] = c_tmp;
		b[i] = b_tmp;
	}
	return c[n-1];
}

int main()
{
	int s1 = 1, a1[s1] = {3};
	int s2 = 5, a2[s2] = {1,4,2,5,3};
	int s3 = 10, a3[s3] = {1,5,8,0,4,7,10,11,5,7};

	cout << find_max_increase_subarray(a2, s1) << endl;   // 1
	cout << find_max_increase_subarray(a2, s2) << endl;   // 3
	cout << find_max_increase_subarray(a3, s3) << endl;   // 5

	return 0;
}














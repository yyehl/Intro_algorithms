/*
 * Filename: 4.1-3.cpp 
 * 
 * 题目：实现最大子数组的暴力算法与递归算法，并分析性能交叉点，然后修改递归算法，在小于性能交叉点时用暴力算法
 * 
 * 
 * 分析：
 * 递归算法的递归式分析：T(n) = 2T(n/2) + n + 2, T(n) = nlogn + 3n -2
 * 暴力算法时间复杂度是：n(n+1)/2
 * 当 nlogn + 3n -2 = n(n + 1) / 2 时，为性能交叉点，计算可得，n处于范围(8, 16), 取 n = 15
 * 
 * 
 **/

#include <iostream>
#include <vector>
using namespace std;

// 暴力算法
vector<int> find_max_subarray(int arr[], int sz)
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
				max = num;
				left = i;
				right = j;
			}
		}
	}
	vector<int> v = {left, right, max};
	return v;
}

// 递归算法

vector<int> cross_max_subarray(int arr[], int low, int mid, int high)
{
	int left, right, max_left = -10000, max_right = -10000;
	int num_left = 0, num_right = 0;
	for (int i = mid; i >= low; --i)
	{
		num_left += arr[i];
		if (num_left > max_left)
		{
			max_left = num_left;
			left = i;
		}
	}
	for (int j = mid + 1; j <= high; ++j)
	{
		num_right += arr[j];
		if (num_right > max_right)
		{
			max_right = num_right;
			right = j;
		}
	}
	vector<int> v = {left, right, max_left + max_right};
	return v;
}


vector<int> find_max_subarray1(int arr[], int low, int high)
{
	vector<int> lv(3), rv(3), cv(3);
	if (low < high)
	{
		int mid = (low + high) / 2;
		lv = find_max_subarray1(arr, low, mid);
		rv = find_max_subarray1(arr, mid + 1, high);
		cv = cross_max_subarray(arr, low, mid, high);
	}
	else
	{
		vector<int> v = {low, high, arr[low]};
		return v;
	}
	
	if (lv[2] >= rv[2] && lv[2] >= cv[2])
		return lv;
	else if (rv[2] >= lv[2] && rv[2] >= cv[2])
		return rv;
	else
		return cv;
}

// 递归算法优化，在n < 15时使用暴力算法


vector<int> find_max_subarray2(int arr[], int low, int high)
{
	vector<int> lv(3), rv(3), cv(3);
	if (high - low >= 15)
	{
		int mid = (low + high) / 2;
		lv = find_max_subarray2(arr, low, mid);
		rv = find_max_subarray2(arr, mid + 1, high);
		cv = cross_max_subarray(arr, low, mid, high);
	}
	else   // n < 15,  使用暴力算法
	{
		return find_max_subarray(arr, high - low + 1);
	}

	if (lv[2] >= rv[2] && lv[2] >= cv[2])
		return lv;
	else if (rv[2] >= lv[2] && rv[2] >= cv[2])
		return rv;
	else 
		return cv;
}


int main()
{	
	int sz = 16;
	int arr[sz] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	vector<int> ret = find_max_subarray2(arr, 0, sz - 1);
	cout << ret[0] << " " << ret[1] << " " << ret[2] << endl;
	return 0;
}


































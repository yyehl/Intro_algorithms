/*
 * Filename: Max_subarray.cpp 
 * 
 * 最大连续子序列问题：在arr[low, high]中，arr[i, j]中子序列的和是所有连续子序列中最大的（其中之一）
 * 
 * 	有很多种方法，从O(n^3)到O(n^2)到O(nlogn)到O(n)的复杂度都有
 * 	下面列出各种算法的代码
 * 
 **/

#include <iostream>
using namespace std;

/******************** O(n^3) 版本 *************************/
void find_max_subarray1(int arr[], int sz, int* ret)   // ret[0]:begin, ret[1]:end, ret[2]:max_num
{
	for (int i = 0; i < sz; ++i)
	{
		for (int j = i; j < sz; ++j)
		{
			int num = 0;
			for (int k = i; k <= j; ++k)
			{
				num += arr[k];
			}
			if (num > ret[2])
			{
				ret[2] = num;
				ret[0] = i;
				ret[1] = j;
			}
		}
	}
}

/******************** O(n^2) 版本 *******************************/
void find_max_subarray2(int arr[], int sz, int* ret)
{
	for (int i = 0; i < sz; ++i)
	{
		int num = 0;
		for (int j = i; j < sz; ++j)
		{
			num += arr[j];
			if (num > ret[2])
			{
				ret[2] = num;
				ret[0] = i;
				ret[1] = j;
			}
		}
	}
}

/********************** O(nlogn) 版本 *****************************************/
#include<vector>

vector<int> cross_max_subarray(int arr[], int low, int mid, int high)
{
	int left, right, max_left = -100000, max_right = -100000;
	int left_num = 0, right_num = 0;
	for (int i = mid; i >= low; --i)
	{
		left_num += arr[i];
		if (left_num > max_left)
		{
			max_left = left_num;
			left = i;
		}
	}
	for (int j = mid + 1; j <= high; ++j)
	{
		right_num += arr[j];
		if (right_num > max_right)
		{
			max_right = right_num;
			right = j;
		}
	}
	vector<int> iv = {left, right, max_left + max_right};
	return iv;
}

vector<int> find_max_subarray3(int arr[], int low, int high)  // [low, high]
{
	vector<int> lv(3), rv(3), cv(3);
	if (low < high)
	{
		int mid = (low + high) / 2;
		lv = find_max_subarray3(arr, low, mid);
		rv = find_max_subarray3(arr, mid + 1, high);
		cv = cross_max_subarray(arr, low, mid, high);
	}
	else          // low >= high, means only one element
	{
		vector<int> iv = {low, high, arr[low]};  // iv[0]:begin, iv[1]:end, iv[2]:max_num
		return iv;
	}

	if (lv[2] >= rv[2] && lv[2] >= cv[2])
		return lv;
	else if (rv[2] >= lv[2] && rv[2] >= cv[2])
		return rv;
	else
		return cv;
}

/************************* o(n) 版本 *************************************/

void find_max_subarray4(int arr[], int sz, int* ret)
{
	int left, right, cur_num = 0, max_num = -100000;
	for (int i = 0; i < sz; ++i)
	{
		if (cur_num <= 0)
		{
			cur_num = arr[i];
			left = i;
		}
		else
			cur_num += arr[i];

		if (cur_num > max_num)
		{
			max_num = cur_num;
			right = i;
		}
	}
	ret[0] = left;
	ret[1] = right;
	ret[2] = max_num;
}

/*********************************************************/

int main()
{
	int sz = 16;
	int arr[sz] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	
	int ret1[3] = {0, 0, 0};
	find_max_subarray1(arr, sz, ret1);
	cout << "O(n^3): " << ret1[0] << " " << ret1[1] << " " << ret1[2] << endl;

	int ret2[3] = {0, 0, 0};
	find_max_subarray2(arr, sz, ret2);
	cout << "O(n^2): " << ret2[0] << " " << ret2[1] << " " << ret2[2] << endl;
	
	vector<int> ret3 = find_max_subarray3(arr, 0, sz - 1);
	cout << "O(nlogn): " << ret3[0] << " " << ret3[1] << " " << ret3[2] << endl;

	int ret4[3] = {0, 0, 0};
	find_max_subarray4(arr, sz, ret4);
	cout << "O(n) :" << ret4[0] << " " << ret4[1] << " " << ret4[2] << endl;

	return 0;
}








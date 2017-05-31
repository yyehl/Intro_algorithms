/*
 * Filename: 8.2-4.cpp 
 * 
 * 题目：设计算法对n个在0~k范围内的元素进行预处理，使得能在O(1)的时间内输出有多少元素在区间[a, b]中，预处理复杂度为O(n+k)
 * 
 * 
 */

#include <iostream>
using namespace std;

int* pre_handle(int arr[], int sz, int k)
{
	int* C = new int[k];
	for (int i = 0; i < k; ++i)  C[i] = 0;
	for (int j = 0; j < sz; ++j)  C[arr[j]]++;
	for (int i = 1; i < k; ++i)  C[i] += C[i-1];
	return C;
}

int main()
{
	int sz = 11, k = 7, arr[sz] = {6,0,2,0,1,3,4,6,1,3,2};
	int *p = pre_handle(arr, sz, k);
	cout << "[0, 1]: " << p[1] << endl;
	cout << "[2, 5]: " << p[5]-p[1] << endl;
	delete [] p;
	return 0;
}






/*
 * Filename: 8.2-1.cpp 
 * 
 * 题目：说明counting_sort在数组A = {6,0,2,0,1,3,4,6,1,3,2}上的操作过程
 * 
 * 
 */
#include <iostream>
using namespace std;

void counting_sort(int arr[], int sz, int k)
{
	int B[sz], C[k];
	for (int i = 0; i < k; ++i)   C[i] = 0;
	for (int j = 0; j < sz; ++j)  C[arr[j]]++;
	for (int i = 1; i < k; ++i)   C[i] += C[i-1];
	for (int j = sz-1; j >= 0; --j)
	{
		B[C[arr[j]]-1] = arr[j];
		--C[arr[j]];
	}
	for (int i = 0; i < sz; ++i)  arr[i] = B[i];
}

int main()
{
	int sz = 11, k = 7, arr[sz] = {6,0,2,0,1,3,4,6,1,3,2};
	for (int i = 0; i < sz; ++i)  cout << arr[i] << " ";  cout << endl;
	counting_sort(arr, sz, k);
	for (int i = 0; i < sz; ++i)  cout << arr[i] << " "; cout << endl;
	return 0;
}














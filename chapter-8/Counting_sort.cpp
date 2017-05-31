/*
 * Filename: Counting_sort.cpp 
 * 
 * 计数排序基本思想：对于元素x，确定小于x的元素个数，那么x应该放置的位置也就确定了。
 * 计数排序适用于n个输入元素中的每一个都是介于 0~k 范围内。
 * 时间复杂度：O(n+k), 计数排序不是比较排序，不受比较排序复杂度最优O(nlogn)的限制
 * 空间复杂度：O(n+k)，需要两个辅助数组 B[0...n-1], C[0...k-1]
 * 
 * 计数排序的特点：
 * １．非比较排序
 * ２．时间复杂度突破O(nlogn)，达到线性时间
 * ３．需要较大的额外辅助空间
 * ４．稳定排序，即key相同的元素排序前后顺序不变
 * 
 */

#include <iostream>
using namespace std;

void counting_sort(int arr[], int sz, int k)  // k为arr中sz个元素都介于0~k-1
{
	int C[k], B[sz];
	for (int i = 0; i < k; ++i)
		C[i] = 0;
	for (int j = 0; j < sz; ++j)
		++C[arr[j]];
	for (int i = 1; i < k; ++i)
		C[i] += C[i-1];
	for (int j = sz-1; j >= 0; --j)
	{
		B[C[arr[j]]-1] = arr[j];
		--C[arr[j]];
	}
	for (int i = 0; i < sz; ++i)
		arr[i] = B[i];
}

int main()
{
	int sz = 9, k = 6, arr[sz] = {2,5,3,0,2,3,0,3};
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	counting_sort(arr, sz, k);
	for (int i = 0; i < sz; ++i) cout << arr[i] << " "; cout << endl;
	return 0;
}














	














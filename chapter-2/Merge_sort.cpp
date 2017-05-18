/*
 * Filename: Merge_sort.cpp
 *
 * 归并排序基本思想：
 * 	　将待排序序列分成两个子序列，将两个子序列分别排序，再把这两个已排序的子序列合并，成为已排序的完整序列。
 * 归并排序时间负责度：O(nlogn)
 * 归并排序空间复杂度：O(n)
 * 
 * 归并排序特点：
 * 	  1. 归并排序采用了分治的基本思想
 * 	　2. 归并排序的缺点是out-place-sort，需要额外的空间，若数据量大，那可能将是一笔很大的开销
 * 	　3. 利用了把两个已排序的子序列合成一个已排序的完整序列只需要O(n)的时间复杂度
 * 	  4. 归并排序是稳定排序
 * 
 */

#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) // arr[low, mid] and arr[mid + 1, high] are sorted
{
	int* tmp = new int[high - low + 1];
	int left = low, right = mid + 1, index = 0;
	while(left <= mid && right <= high)
	{
		if (arr[left] <= arr[right])  // 一定要是<=，才能保证稳定排序，<无法保证
		{
			tmp[index] = arr[left];
			++left;
		}
		else
		{
			tmp[index] = arr[right];
			++right;
		}
		++index;
	}
	while(left <= mid)
	{
		tmp[index] = arr[left];
		++left;
		++index;
	}
	while(right <= high)
	{
		tmp[index] = arr[right];
		++right;
		++index;
	}
	for (int i = 0; i < index; ++i, ++low)  // 注意边界条件，i < index, 不能 =
		arr[low] = tmp[i];
	
	delete [] tmp;
}

void merge_sort(int arr[], int low, int high)  // arr[low, high]
{
	if (low < high)                            // at list two elements
	{
		int mid = (low + high) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	int arr[10] = {5, 3, 9, 0, 4, 6, 2, 1, 8, 7};
	cout << "原　序　列：";
	for (int i = 0; i < 10; ++i)  cout << arr[i] << " ";
	cout << endl;
	merge_sort(arr, 0, 9);
	cout << "排序后序列：";
	for (int i = 0; i < 10; ++i)  cout << arr[i] << " ";
	cout << endl;
	return 0;
}









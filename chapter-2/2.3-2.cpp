/*
 * Filename: 2.3-2.cpp 
 * 
 * 题目：重写merge，不使用哨兵，而是一旦数组Ｌ或Ｒ的所有元素均被复制回Ａ就立刻停止，再将另一数组的剩余部分复制回Ａ
 * 
 */


void merge(int arr[], int low, int mid, int high) // arr[low, mid] and arr[mid + 1, high] are sorted
{
	int* tmp = new int[high - low + 1];
	int left = low, right = mid + 1, index = 0;
	while (left <= mid && right <= high)
	{
		if (arr[left] <= arr[right]) // <= 保证了稳定排序
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
	while (left <= mid)
	{
		tmp[index] = arr[left];
		++left;
		++index;
	}
	while (right <= high)
	{
		tmp[index] = arr[right];
		++right;
		++index;
	}
	for (int i = 0; i < index; ++i, ++low)
		arr[low] = tmp[i];
}


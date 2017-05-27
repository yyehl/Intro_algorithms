/*
 * Filename: 6.5-6.cpp 
 * 
 * 用insertion_sort中循环部分的思想代替heap_increase_key中的swap操作
 * 
 */

// 原使用swap的版本
void heap_increase_key_swap(int arr[], int heap_sz, int i, int key)
{
	if (arr[i] < key)
	{
		arr[i] = key;
		int p = (i-1)/2;
		while (p >= 0 && arr[i] > arr[p])
		{
			swap(arr[i], arr[p]);
			i = p;
			p = (i-1)/2;
		}
	}
}

// 不使用swap的版本
void heap_increase_key(int arr[], int heap_sz, int i, int key)
{
	if (arr[i] < key)
	{
		int p = (i-1)/2;
		while (p >= 0 && key > arr[p])
		{
			arr[i] = arr[p];
			i = p;
			p = (i-1)/2;
		}
		arr[i] = key;
	}
}





/**
 *  Filename: 2.1-2.cpp 
 * 	
 * 	题目：重写INSERTION_SORT,使之按非升序排列
 * 	
 **/

#include <vector>
#include <iostream>
using namespace std;

void Insertion_sort_lower(vector<int>& iv)
{
	for (int i = 1; i < iv.size(); ++i)
	{
		int key = iv[i];
		int j = i - 1;
		while (j >= 0 && iv[j] < key)
		{
			iv[j + 1] = iv[j];
			--j;
		}
		iv[j + 1] = key;
	}
}

int main()
{
	vector<int> v = {5, 3, 9, 7, 10, 1, 4, 7, 0, 2, 8};
	cout << "原　序　列：";
	for (auto i : v)  cout << i << " ";
	cout << endl;
	Insertion_sort_lower(v);
	cout << "排序后序列：";
	for (auto i : v)  cout << i << " ";
	cout << endl;
	return 0;
}






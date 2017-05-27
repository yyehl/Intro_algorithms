/*
 * Filename: 6.5-3.cpp 
 * 
 * 用最小堆实现最小优先队列
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class priority_min_queue
{
public:
	priority_min_queue(vector<int> v = vector<int>()) : repo(v) 
	{
		build_min_heap(repo.size());
	}
	
	int min() const { return repo[0]; }

	int extract_min()
	{
		int ret = repo[0];
		swap(repo[0], repo[repo.size()-1]);
		repo.pop_back();
		min_heapify(repo.size(), 0);
		return ret;
	}

	void decrease_key(int i, int key)
	{
		if (key < repo[i])
		{
			repo[i] = key;
			int p = (i-1)/2;
			while (p >= 0 && repo[i] < repo[p])
			{
				swap(repo[i], repo[p]);
				i = p;
				p = (i-1)/2;
			}
		}
	}

	void insert(const int x)
	{
		repo.push_back(x);
		int i = repo.size()-1, p = (i-1)/2;
		while (p >= 0 && repo[i] < repo[p])
		{
			swap(repo[i], repo[p]);
			i = p;
			p = (i-1)/2;
		}
	}

private:
	vector<int> repo;

	void min_heapify(int heap_sz, int i)
	{
		int left = 2*i+1, right = 2*i+2, index = i;
		if (left < heap_sz && repo[left] < repo[index])
			index = left;
		if (right < heap_sz && repo[right] < repo[index])
			index = right;
		if (i != index)
		{
			swap(repo[i], repo[index]);
			min_heapify(heap_sz, index);
		}
	}
    void build_min_heap(int heap_sz)
	{
		int p = (heap_sz-2)/2;
		while (p >= 0)
		{
			min_heapify(heap_sz, p);
			p--;
		}
	}
};


int main()
{
	vector<int> iv = {9, 4, 1, 7, 8, 3, 6, 2, 5, 10};
	priority_min_queue pmq(iv);
	cout << "1  " << pmq.min() << endl;
	cout << "1  " << pmq.extract_min() << endl;
	cout << "2  " << pmq.min() << endl;
	pmq.insert(0);
	cout << "0  " << pmq.min() << endl;
	pmq.decrease_key(3, -1);
	cout << "-1 " << pmq.min() << endl;
	return 0;
}





















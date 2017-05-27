/**
 * Filename: Priority_queue.h
 *  
 * 基于最大堆实现优先队列的数据结构
 */

#include <vector>
#include <algorithm>
using namespace std;

class priority_queue
{
public:
	explicit priority_queue(vector<int> v = vector<int>());

	void insert(const int x);
	int max() const;
	int extract_max();
	void increase_key(int i, int key);
	void decrease_key(int i, int key);
	
private:
	vector<int> repo;

	void max_heapify(int heap_sz, int i);
	void build_max_heap(int heap_sz);
};

priority_queue::priority_queue(vector<int> v) : repo(v)
{
	build_max_heap(v.size());
}

void priority_queue::insert(const int x)
{
	repo.push_back(x);
	int i = repo.size()-1, p = (i-1)/2;
	while (p >= 0 && repo[p] < repo[i])
	{
		swap(repo[p], repo[i]);
		i = p;
		p = (i-1)/2;
	}
}

int priority_queue::max() const 
{
	return repo[0];
}

int priority_queue::extract_max()
{
	int ret = repo[0];
	swap(repo[0], repo[repo.size()-1]);
	repo.pop_back();
	max_heapify(repo.size(), 0);
	return ret;
}

void priority_queue::increase_key(int i, int key)
{
	if (key > repo[i])
	{
		repo[i] = key;
		int p = (i-1)/2;
		while (p >= 0 && repo[p] < repo[i])
		{
			swap(repo[p], repo[i]);
			i = p;
			p = (i-1)/2;
		}
	}
}

void priority_queue::decrease_key(int i, int key)
{
	if (key < repo[i])
	{
		repo[i] = key;
		max_heapify(repo.size(), i);
	}
}

void priority_queue::max_heapify(int heap_sz, int i)
{
	int left = 2*i+1, right = 2*2+2, index = i;
	if (left < heap_sz && repo[index] < repo[left])
		index = left;
	if (right < heap_sz && repo[index] < repo[right])
		index = right;
	if (i != index)
	{
		swap(repo[i], repo[index]);
		max_heapify(heap_sz, index);
	}
}

void priority_queue::build_max_heap(int heap_sz)
{
	int p = (heap_sz-2)/2;
	while (p >= 0)
		max_heapify(heap_sz, p--);
}



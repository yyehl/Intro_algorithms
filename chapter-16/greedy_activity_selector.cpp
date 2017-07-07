/*
 * Filename: greedy_activity_selector.cpp 
 * 
 * 活动选择问题，在某个确定区间内尽可能选择最多的可兼容活动数量
 * 
 * 贪心算法
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int greedy_activity_selector(const vector<int>& vs, const vector<int>& vf)
{
	int ret = 1;
	int k = 0, m = k + 1;
	while (m < vs.size())
	{
		if (vs[m] >= vf[k])
		{
			ret++;
			k = m;
		}
		m++;
	}
	return ret;
}

int main()
{
	vector<int> v1 = {1,3,0,5,3,5,6,8,8,2,12};
	vector<int> v2 = {4,5,6,7,9,9,10,11,12,14,16};

	cout << greedy_activity_selector(v1, v2) << endl;
	return 0;
}















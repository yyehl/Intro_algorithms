/*
 * Filename: 16.1-2.cpp 
 * 
 * 每一次选择最晚开始的活动　贪心算法
 * 
 */

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <functional>
#include <map>
#include <utility>
using namespace std;

int greedy_activity_selector(const vector<int>& vs, const vector<int>& vf)
{
	multimap<int, int, greater<int>> sfmap;
	for (int i = 0; i < vs.size(); i++)
		sfmap.insert(pair<int, int>(vs[i], vf[i]));
	
	for (multimap<int, int>::iterator iter = sfmap.begin(); iter != sfmap.end(); ++iter)
	{
		cout << iter->first << "  " << iter->second << endl; 
	}

	multimap<int, int>::iterator iter = sfmap.begin(), pter = iter; ++pter;
	int ret = 1;
	while (iter != sfmap.end() && pter != sfmap.end())
	{
		if (pter->second <= iter->first)
		{
			ret++;
			iter = pter;
		}
		pter++;
	}

	return ret;
}

int main()
{
	vector<int> vs = {1,3,0,5,3,5,6,8,8,2,12};
	vector<int> vf = {4,5,6,7,9,9,10,11,12,14,16};

	cout << greedy_activity_selector(vs, vf) << endl;
	return 0;
}












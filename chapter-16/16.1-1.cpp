/*
 * Filename: 16.1-1.cpp 
 * 
 * 活动选择问题的动态规划解法   // 有ＢＵＧ,暂时不知道怎么改
 * 
 */

#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int dp_activity_selector_aux(const vector<int>& vs, const vector<int>& vf, vector<vector<int> >& c, int i, int j)
{
	if (c[i][j] != -1)  return c[i][j];

	int q = 1;
	for (int k = i + 1; k < j; ++k)
	{
		if (vf[i] <= vs[k] && vf[k] <= vs[j])
			q = max(q, dp_activity_selector_aux(vs, vf, c, i, k) + dp_activity_selector_aux(vs, vf, c, k, j) + 1);
		else if (vf[i] <= vs[k])
			q = max(q, dp_activity_selector_aux(vs, vf, c, i, k) + 1);
		else if (vf[k] <= vs[j])
			q = max(q, dp_activity_selector_aux(vs, vf, c, k, j) + 1);
		else 
			q = max(q, 1);
	}
	c[i][j] = q;
	return c[i][j];
}

int dp_activity_selector(const vector<int>& vs, const vector<int>& vf)
{
	int len = vs.size();
	vector<vector<int> > c(len, vector<int>(len, -1));

	return dp_activity_selector_aux(vs, vf, c, 0, len-1);
}


int main()
{
	vector<int> vs = {1,3,0,5,3,5,6,8,8,2,12};
	vector<int> vf = {4,5,6,7,9,9,10,11,12,14,16};

	cout << dp_activity_selector(vs, vf) << endl;
	return 0;
}










/*
 * Filename: 01bag.cpp 
 * 
 * 01背包问题，动态规划解法
 * 
 * 一个背包最多能装不超过Ｗ重量的东西，求能装下的最大价值
 * 
 * 有一系列东西
 * 
 * ｗ[]表示每个东西的重量
 * v[]表示每个东西的价值
 * 
 * 01背包问题的意思是，一个东西要么拿要么不拿，不能拿二分之一，动态规划做
 * 
 * 分数背包问题的意思是，一个东西可以分开拿，分数背包问题用贪心做，很简单
 * 
 */

#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int dp_01bag(const vector<int>& w, const vector<int>& v, int weight)
{
	int M = w.size() + 1, N = weight + 1;
	int f[M][N];
	for (int i = 0; i < M; i++)  f[i][0] = 0;
	for (int i = 0; i < N; i++)  f[0][i] = 0;

	for (int i = 1; i < M; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			if (w[i-1] <= j)
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i-1]]+v[i-1]);
			else 
				f[i][j] = f[i-1][j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << f[i][j] << " ";
		cout << endl;
	}


	return f[M-1][N-1];
}

int main()
{
	vector<int> w = {2,2,6,5,4};
	vector<int> v = {6,3,5,4,6};

	cout << dp_01bag(w, v, 10) << endl;
	return 0;
}
























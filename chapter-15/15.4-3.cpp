/*
 * Filename: 15.4-3.cpp 
 * 
 * 带备忘版本的LCS，自顶向下
 * 
 **/

#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int lcs_top_to_down_aux(int a1[], int k, int a2[], int l, vector<vector<int> >& c)
{
	if (c[k][l] != -1)   return c[k][l];

    if (k == 0 || l == 0)
	{
		c[k][l] = 0;
		return c[k][l]; 
	}

	if (a1[k-1] == a2[l-1]) 
	{
		c[k][l] = lcs_top_to_down_aux(a1, k-1, a2, l-1, c) + 1;
	}
	else 
	{
		c[k][l] = max(lcs_top_to_down_aux(a1, k-1, a2, l, c), lcs_top_to_down_aux(a1, k, a2, l-1, c));
	}
	return c[k][l];
}

int lcs_top_to_down(int a1[], int m, int a2[], int n)
{
	vector<vector<int> > c(m+1, vector<int>(n+1));
	for (int i = 0; i <= m; ++i)   c[i][0] = 0;
	for (int i = 0; i <= n; ++i)   c[0][i] = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			c[i][j] = -1;
	
	int k = m, l = n;

	return lcs_top_to_down_aux(a1, k, a2, l, c);
}

int main()
{
	int m = 8, n = 9;
	int a1[m] = {1,0,0,1,0,1,0,1}, a2[n] = {0,1,0,1,1,0,1,1,0};

	cout << lcs_top_to_down(a1, m, a2, n) << endl;
	return 0;
}


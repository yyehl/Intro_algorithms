/*
 * Filename: 15.4-1.cpp 
 * 
 * 求LCS
 * 
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

int lcs_dp(int arr1[], int m, int arr2[], int n)
{
	int c[m+1][n+1];
	for (int i = 0; i <= m; ++i)  c[i][0] = 0;
	for (int i = 0; i <= n; ++i)  c[0][i] = 0;

	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (arr1[i-1] == arr2[j-1]) 
				c[i][j] = c[i-1][j-1] + 1;
			else  
				c[i][j] = max(c[i-1][j], c[i][j-1]);
		}

	return c[m][n];
}

int main()
{
	int m = 8, n = 9;
	int arr1[m] = {1,0,0,1,0,1,0,1}, arr2[n] = {0,1,0,1,1,0,1,1,0};
	
	cout << lcs_dp(arr1, m, arr2, n) << endl;
	return 0;
}















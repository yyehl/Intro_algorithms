/*
 * Filename: 15.4-1.cpp 
 * 
 * 直接借用c[m+1][n+1]重构解
 * 
 **/

#include <iostream>
#include <stdlib.h>
using namespace std;

void lsc_dp(int arr1[], int m, int arr2[], int n)
{
	int c[m+1][n+1];
	for (int i = 0; i <= m; ++i)  c[i][0] = 0;
	for (int i = 0; i <= n; ++i)  c[0][i] = 0;

	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (arr1[i-1] == arr2[j-1])
				c[i][j] = c[i-1][j-1] + 1;
			else 
				c[i][j] = max(c[i-1][j], c[i][j-1]);

	cout << c[m][n] << endl;

	int len = c[m][n], l = len;
	int tmp[len];
	for (int i = m, j = n; i > 0 && j > 0; )
	{
		if (arr1[i-1] == arr2[j-1])
		{
			tmp[--l] = arr1[i-1];
			--i;
			--j;
		}
		else if (c[i-1][j] > c[i][j-1])
			--i;
		else 
			--j;
	}

	for (int i = 0; i < len; ++i) cout << tmp[i] << " ";
	cout << endl;

}

int main()
{
	int m = 8, n = 9;
	int a1[m] = {1,0,0,1,0,1,0,1};
	int a2[n] = {0,1,0,1,1,0,1,1,0};

	lsc_dp(a1, m, a2, n);
	return 0;
	
}



























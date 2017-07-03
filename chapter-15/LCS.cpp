/*
 * Filaname: LCS.cpp 
 * 
 * 最长公共子序列问题，dp求解
 * 
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

void lcs_dp(char s1[], int m, char s2[], int n)
{
	int c[m+1][n+1];    //存储子结构最优解
	char b[m+1][n+1];   //用于重构最优解

	for (int i = 0; i <= m; ++i)  c[i][0] = 0;     //先把当其中一个序列长度为0时的情况，lcs都置为0 
	for (int i = 0; i <= n; ++i)  c[0][i] = 0;

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s1[i-1] == s2[j-1])	
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 't';
			}
			else 
			{
				if (c[i-1][j] > c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					b[i][j] = 'z';
				}
				else 
				{
					c[i][j] = c[i][j-1];
					b[i][j] = 's';
				}
			}
		}
	}
	cout << "LCS length: " << c[m][n] << endl;


	int len = min(m, n);   // 重构最优解
	char lcs[len];
	int index = 0;
	for (int i = m, j = n; i > 0 && j > 0; )
	{
		if (b[i][j] == 't') 
		{
			lcs[index++] = s1[i-1];
			i--;
			j--;
		}
		else if (b[i][j] = 'z')  i--;
		else j--;
	}
	for (int i = index-1; i >= 0; --i)
		cout << lcs[i] << " ";
	cout << endl;
}


int main()
{
	int s1_size = 6, s2_size = 7;
	char s1[s1_size] = {'B', 'D', 'C', 'A', 'B', 'A'};
	char s2[s2_size] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};

	lcs_dp(s1, s1_size, s2, s2_size);
	return 0;
}











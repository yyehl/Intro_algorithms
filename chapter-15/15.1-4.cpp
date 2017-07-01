/*
 * Filename: 15.1-4.cpp 
 * 
 * 15.1-3的拓展，不仅输出最优解，还输出切割方案
 * 
 */

#include <stdlib.h>
#include <iostream>
using namespace std;


void cut_pod_extern(int p[], int n)
{
	int r[n+1]; // 存最优解
	int c[n+1]; // 存最优解时的切割数 
	int s[n+1]; // 存最优解时的首段长度

	r[0] = 0;
	c[0] = 0, c[1] = 0;
	s[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		int q = -1;
		for (int j = 1; j <= i; ++j)
		{
			int f = 1;
			if (i == j) f = 0;

			int tmp = p[j] + r[i-j] - c[i-j] - f;
			if (q < tmp)
			{
				q = tmp;
				s[i] = j;
				c[i] = c[i-j] + f;
			}	
		}
		r[i] = q;
	}
	
	cout << r[n] << " : ";
	int i = n;
	while (i > 0)
	{
		cout << s[i] << " ";
		i = i - s[i];
	}
	cout << endl;
}





int main()
{
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};
	cut_pod_extern(p, 1);
	cut_pod_extern(p, 2);
	cut_pod_extern(p, 3);
	cut_pod_extern(p, 4);
	cut_pod_extern(p, 5);
	
	return 0;
}









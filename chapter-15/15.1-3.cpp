/*
 * Filename: 15.1-3.cpp 
 * 
 * 钢条切割问题的拓展，加入每次切割还需要固定的成本c，假设固定成本为1
 * 
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

int cut_pod_c(int p[], int n)
{

	int r[n+1], c[n+1];
	r[0] = 0, c[0] = 0, c[1] = 0;

	for (int i = 1; i <= n; ++i)
	{
		int q = 0;
		for (int j = 1; j <= i; j++)
		{
			int s = 1;
			if (i == j) s = 0;

			int tmp = p[j] + r[i-j] - c[i-j] - s;
			if (q < tmp)
			{
				q = tmp;
				c[i] = c[i-j] + s;
			}
		}
		r[i] = q;
	}
	return r[n];
}

int main()
{
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};

	cout << cut_pod_c(p, 0) << " "
		 << cut_pod_c(p, 1) << " "
		 << cut_pod_c(p, 2) << " "
		 << cut_pod_c(p, 3) << " "
		 << cut_pod_c(p, 4) << " "
		 << cut_pod_c(p, 5) << " " << endl;
	
	return 0;
}





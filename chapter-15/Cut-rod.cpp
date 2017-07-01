/*
 * Filename: Cut-rod.cpp 
 * 
 * 15.1节的切割钢条问题
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <utility>
using namespace std;


// no dp
int cut_pod1(int p[], int n)
{
	if (n == 0)
		return 0;
	
	int q = 0;
	for (int i = 1; i <= n; ++i)
	{
		q = max(q, p[i-1] + cut_pod1(p, n-i));
	}
	return q;
}

// dp top-to-down

int cut_pod_dp_top_to_down_aux(int p[], int r[], int n)
{
	if (n == 0) return 0;
	if (r[n-1] >= 0) return r[n-1];
	int q = 0;
	for (int i = 1; i <= n; i++)
	{
		q = max(q, cut_pod_dp_top_to_down_aux(p, r, i-1) + p[n-i]);
		// q = max(q, cut_pod_dp_top_to_down(p, r, n-i) + p[i-1]);  一样的
	}
	r[n-1] = q;
	return r[n-1];
}

int cut_pod_dp_top_to_down(int p[], int n)
{
	if (n == 0) return 0;
	int r[n];
	for (int i = 0; i < n; ++i)
		r[i] = -1;
	return cut_pod_dp_top_to_down_aux(p, r, n);
}


// dp down-to-top   

int cut_pod_dp_down_to_top(int p[], int n)
{
	if (n == 0) return 0;
	int r[n+1];
	r[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int q = -1;
		for (int j = 1; j <= i; ++j)
		{
			q = max(q, p[j-1] + r[i-j]);		
		}
		r[i] = q;
	}
	return r[n];
}

// 不仅保存最优解，而且保存最优解的切割方案

void cut_pod_dp_down_to_top_extern(int p[], int n)
{
	if (n == 0)  return ;
	int r[n+1];
	int s[n+1];

	r[0] = 0;
	s[0] = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		int q = 0;
		for (int j = 1; j <= i; ++j)
		{
			if (q < p[j-1] + r[i-j])
			{
				q = p[j-1] + r[i-j];
				s[i] = j;
			}
		}
		r[i] = q;
	}
	
	for (int i = 0; i < n+1; ++i)
		cout << r[i] << " ";  cout << endl;
	for (int i = 0; i < n+1; ++i)
		cout << s[i] << " ";  cout << endl;
}

int main()
{
	int p[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	cout << cut_pod1(p, 1) << " " << cut_pod1(p, 2) << " " <<  cut_pod1(p, 3) << " " << cut_pod1(p, 4) << endl;

	cout << cut_pod_dp_top_to_down(p,1) << " " << cut_pod_dp_top_to_down(p, 2) << " "
		 << cut_pod_dp_top_to_down(p, 3) << " " << cut_pod_dp_top_to_down(p, 4) << endl;

	cout << cut_pod_dp_down_to_top(p,1) << " " << cut_pod_dp_down_to_top(p,2) << " " << cut_pod_dp_down_to_top(p,3) << " "
		 << cut_pod_dp_down_to_top(p, 4) << endl;

	cut_pod_dp_down_to_top_extern(p, 10);
	return 0;
}











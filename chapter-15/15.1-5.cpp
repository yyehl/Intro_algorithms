/*
 * Filename: 15.1-5.cpp 
 * 
 * 用O(n)方法求第n斐波那契数列
 * 
 */

// 递归方法求解，复杂度指数级
int foo(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else 
		return foo(n-1) + foo(n-2);
}

// dp
int fooo(int n)
{
	int arr[n+1];
	arr[0] = 0, arr[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr[n];
}


#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	clock_t start1, start2, finish1, finish2;
	start1 = clock();
	for (int i = 0; i < 100; ++i)
		foo(30);
	finish1 = clock();
	double time = (finish1 - start1)/CLOCKS_PER_SEC;
	cout << "foo" << " " << foo(30) << "  " << time << " s" << endl;

	start2 = clock();
	for (int i = 0; i < 100; ++i)
		fooo(30);
	finish2 = clock();
	double time2 = (finish2 - start2)/CLOCKS_PER_SEC;
	cout << "fooo" << " " << fooo(30) << " " << time2 << " s" << endl;

	return 0;
}





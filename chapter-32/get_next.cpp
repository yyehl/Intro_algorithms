/**
 *  Filename: get_next.cpp
 * 
 * KMP算法的预处理阶段，计算next数组
 * 
 */

#include <iostream>
#include <string>
using namespace std;

void get_next(const string& T, int next[])
{
	int i = 1, j = 0, len = T.size()-1;
	next[0] = 0;
	next[1] = 1;

	while (i < len)    // i < len 	
	{
		if (j == 0 && T[i] != T[j])
		{
			++i;
			next[i] = 1;
		}
		else if (T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j+1;
		}
		else 
			j = next[j-1];   // j = next[j-1]  回溯，最难理解的部分
	}
}

int main()
{
	string T = "ababaaaba";
	int sz = T.size();
	int next[sz];
	get_next(T, next);
	cout << T << endl;
	for (int i = 0; i < sz; ++i)	cout << next[i];
	cout << endl;
	return 0;
}








/*
 * Filename:2.1-4.cpp
 * 
 * 题目：
 * 	　输入:两个n位以二进制数组形式储存的整数
 * 	　输出:一个n+1位的以二进制数组形式储存的整数
 */


#include <vector>
#include <iostream>
using namespace std;

vector<int> foo(const vector<int>& v1, const vector<int>& v2)
{
	vector<int> ret(v1.size() + 1, 0);
	for (int i = v1.size() - 1; i >= 0 ; --i)
	{
		if (v1[i] + v2[i] == 1)
		{
			if (ret[i + 1] == 0)
				ret[i + 1] = 1;
			else   // 要么等于０，要么等于１
			{
				ret[i + 1] = 0;
				ret[i] = 1;   //进位
			}
		}
		else if (v1[i] + v2[i] == 2)
		{
			ret[i] = 1;
		}
	}
	return ret;
}

int main()
{
	vector<int> iv1 = {1, 1, 1, 0}; // 14
	vector<int> iv2 = {1, 0, 0 ,1}; // 9
	vector<int> v = foo(iv1, iv2);
 	cout << "输出应为: 1 0 1 1 1 " << endl << "输　　出: ";
	for (auto i : v)  cout << i << " "; 
	cout << endl;
	return 0;
}


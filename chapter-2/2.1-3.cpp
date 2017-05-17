/*
 * Filename: 2.1-3.cpp
 * 
 * 题目：
 * 	　输入：一个序列，一个值v
 * 	  输出：使得v = a[i]的下标i，若v不在a中出现，则v为特殊值NIL
 * 
 * 
 **/

#include <vector>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	vector<string> sv;
	string s;
	while (cin >> s && s != "END")
		sv.push_back(s);
	string v;
	cin >> v;
	
	int flag = 0;  // 如果v在sv里面,那么flag变为１
	for (int i = 0; i < sv.size(); ++i)
	{
		if (sv[i] == v)
		{
			flag = 1;
			cout << i << " ";
		}
	}
	if (flag == 0)
	{
		v = "NIL";
		cout << "v is not in sv, v = " << v << endl;
	}
	return 0;
}











/*
 * Filename: 10.1-7.cpp 
 * 
 * 用两个队列实现一个栈
 * 
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class sss
{
public:
	int top()
	{
		return q1.back();
	}
	void push(int x)
	{
		q1.push(x);
	}
	void pop()
	{
		while (q1.size() > 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}
private:
	queue<int> q1;
	queue<int> q2;
};


int main()
{
	stack<int> si;
	sss ss;
	for (int i = 0; i < 5; ++i)
	{
		ss.push(i);
		si.push(i);
		cout << ss.top() << " " << si.top() << endl;
	}
	for (int i = 0; i < 3; ++i)
	{
		ss.pop();
		si.pop();
		cout << ss.top() << " " << si.top() << endl;
	}
	return 0;
}





/*
 * Filename: 10.1-6.cpp 
 * 
 * 用两个栈实现一个队列。
 * 
 * 分析：栈后进先出，队列先进先出，用栈实现队列，肯定出的时候需要出栈底元素，所以可以将一个栈作为主要存储，另一个作为辅助来实现
 * 
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class qqq
{
public:
	int front()
	{
		if (!s2.empty())
		{
			return s2.top();
		}
		if (!s1.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
		if (s1.empty() && s2.empty())
			cout << " no data! " << endl;
	}
	int back()
	{
		if (!s2.empty())
		{
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
			return s1.top();
		}
		if (!s1.empty())
		{
			return s1.top();
		}
		if (s2.empty() && s1.empty())
			cout << "no data!" << endl;
	}
	void dequeue()
	{
		if (!s2.empty())
			s2.pop();
		else if (!s1.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
		}
		else
			cout << "no data!" << endl;
	}
	void inqueue(int x)
	{
		if (!s2.empty())
		{
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		s1.push(x);
	}
private:
	stack<int> s1;
	stack<int> s2;
};

int main()
{
	qqq qq;
	queue<int> sq;
	for (int i = 0; i < 5; ++i) 
	{
		qq.inqueue(i);
		cout << qq.front() << " " << qq.back() << endl;
		sq.push(i);
		cout << sq.front() << " " << sq.back() << endl;
	}
	for (int i = 0; i < 3; ++i)
	{
		qq.dequeue();
		cout << qq.front() << " " << qq.back() << endl;
		sq.pop();
		cout << sq.front() << " " << sq.back() << endl;
	}
	return 0;
}








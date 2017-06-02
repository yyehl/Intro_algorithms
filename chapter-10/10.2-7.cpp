/*
 * Filename: 10.2-7.cpp 
 * 
 * 在O(n)时间内实现对单链表的逆序, 非递归
 * 
 */

#include <iostream>
#include <queue>
using namespace std;

struct list_node
{
	int data;
	list_node* next;
};

class list
{
public:
	list()
	{
		head = new list_node;
		head->data = 0;
		head->next = nullptr;
	}
	~list()
	{
		while (head->next != nullptr)
		{
			list_node* tmp = head->next;
			head->next = head->next->next;
			delete tmp;
		}
		delete head;
	}
	int front() const { return head->next->data; }
	int insert_front(int x) 
	{
		list_node* tmp = new list_node;
		tmp->data = x;
		tmp->next = head->next;
		head->next = tmp;
	}
	void erase_front()
	{
		list_node* tmp = head->next;
		head->next = tmp->next;
		delete tmp;
	}
	void print()
	{
		for (list_node* cur = head->next; cur != nullptr; cur = cur->next)
		{
			cout << cur->data << " ";
		}
		cout << endl;
	}
	bool empty() const { return (head->next == nullptr); }
private:
	list_node* head;
};


void reverse_list1(list& l)
{
	queue<int> ss;
	while (!l.empty())
	{
		ss.push(l.front());
		l.erase_front();
	}
	while (!ss.empty())
	{
		l.insert_front(ss.front());
		ss.pop();
	}
}


int main()
{
	list l;
	for (int i = 0; i < 10; i++)  l.insert_front(i);
	l.print();
	reverse_list1(l);
	l.print();
	return 0;
}











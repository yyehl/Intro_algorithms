/*
 * Filename: Priority_queue.cpp
 * 
 * 优先队列测试源文件
 * 
 */

#include <iostream>
#include "Priority_queue.h"

int main()
{
	vector<int> iv = {4, 10, 1, 9, 3, 7, 5, 2, 8, 2};
	for (int i = 0; i < iv.size(); ++i) cout << iv[i] << " "; cout << endl;
	priority_queue pq(iv);
	cout << "10  " << pq.max() << endl;
	pq.increase_key(3, 100);
	cout << "100 " << pq.max() << endl;
	cout << "100 " << pq.extract_max() << endl;
	cout << "10  " << pq.extract_max() << endl;
	pq.insert(99);
	cout << "99  " << pq.max() << endl;
	return 0;
}

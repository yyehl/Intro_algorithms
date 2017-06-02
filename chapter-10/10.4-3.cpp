/*
 * Filename: 10.4-3.cpp 
 * 
 * 非递归遍历二叉树，辅助栈
 * 
 */

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

void print(TreeNode* root)
{
	cout << root->data << " ";
}
void pre_traverse(TreeNode* root)
{
	if (root == nullptr) return ;
	stack<int> ss;

	while (root != nullptr || !ss.empty())
	{
		while (root)
		{
			ss.push(root);
			root = root->left;
		}
		root = ss.top();
		print(root->data);
		ss.pop();
		root = root->right;
	}
}









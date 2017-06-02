/*
 * Filename: 10.4-2.cpp 
 * 
 * O(n)时间递归遍历二叉树
 * 
 * 
 */


#include <iostream>
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
	print(root);
	pre_traverse(root->left);
	pre_traverse(root->right);
}









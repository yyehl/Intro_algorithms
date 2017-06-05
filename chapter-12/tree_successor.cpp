/*
 * Filename: tree_successor.cpp 
 * 
 * 寻找二叉树某节点的后继
 */


#include "Binary_search_tree.h"

TreeNode* tree_successor(TreeNode* root)
{
	if (root->right != nullptr)
	{
		root = root->right;
		while (root->left != nullptr)
			root = root->left;
	}
	else
	{
		if (root->parent == nullptr)
			return root;
		else if (root->parent->left == root)
			root = root->parent;
		else
		{
			while (root->parent->right == root)
				root = root->parent;
			root = root->parent;
		}
	}
	return root;
}

int main()
{
	int sz = 5, arr[sz] = {5,10,99,34,66};
	binary_search_tree bst;
	bst.build_tree(arr, sz);
	bst.print(bst.get_root());
	std::cout << std::endl;
	std::cout << tree_successor(bst.find(10))->val << std::endl;
	return 0;
}








/*
 * Filename: 12.2-2.cpp 
 * Tree_max, Tree_min的递归版本
 * 
 */

#include "Binary_search_tree.h"

int tree_min(TreeNode* root)
{
	if (root->left == nullptr)
		return root->val;
	else
		return tree_min(root->left);
}

int tree_max(TreeNode* root)
{
	if (root->right == nullptr)
		return root->val;
	else
		return tree_max(root->right);
}

int main()
{
	int sz = 5, arr[sz] = {3,5,7,1,90};
	binary_search_tree bst;
	bst.build_tree(arr, sz);
	bst.print(bst.get_root());
	std::cout << std::endl;
	std::cout << tree_max(bst.get_root()) << " " << tree_min(bst.get_root()) << std::endl;
	return 0;
}





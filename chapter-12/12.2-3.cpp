/*
 * Filename: 12.2-3.cpp 
 * 
 * 二叉搜索树的前驱
 */


#include "Binary_search_tree.h"


TreeNode* tree_predecessor(TreeNode* root)
{
	if (root->left != nullptr)
		return root->left;
	else
	{
		if (root->parent == nullptr)
			return nullptr;
		else if (root == root->parent->right)
			return root->parent;
		else
		{
			while (root == root->parent->left)
				root = root->parent;
			return root->parent;
		}
	}
}

int main()
{
	int sz = 5, arr[sz] = {4,10,3,9,0};
	binary_search_tree bst;
	bst.build_tree(arr, sz);
	bst.print(bst.get_root());
	std::cout << std::endl;

	std::cout << tree_predecessor(bst.find(10))->val << std::endl;
	return 0;
}



















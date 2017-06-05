/*
 * Filename: 12.3-1.cpp 
 * 
 * tree_insert的递归版本
 * 
 */

void tree_insert(TreeNode* root, int x)
{
	if (x < root->val)
	{
		if (root->left == nullptr)
		{
			TreeNode* tmp = new TreeNode;
			root->left = tmp;
			tmp->val = x;
			tmp->parent = root;
			tmp->left = nullptr;
			tmp->right = nullptr;
		}
		else 
			tree_insert(root->left, x);
	}
	else 
	{
		if (root->right == nullptr)
		{
			TreeNode* tmp = new TreeNode;
			root->right = tmp;
			tmp->val = x;
			tmp->parent = root;
			tmp->left = nullptr;
			tmp->right = nullptr;
		}
		else
			tree_insert(root->right, x);
	}
}





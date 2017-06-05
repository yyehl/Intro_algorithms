/*
 * Filename: Binary_search_tree.h 
 * 
 */

#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
};

class binary_search_tree
{
public:
	binary_search_tree()
	{
		root = nullptr;
	}
	~binary_search_tree()
	{
		destroy_tree(root);
	}
	void insert(int v)
	{
		TreeNode* ptr = new_node(v);
		if (root == nullptr)
		{
			root = ptr;
			return ;
		}
		TreeNode* x = root;
		TreeNode* y;
		while (x != nullptr)
		{
			y = x;
			if (v < x->val)
				x = x->left;
			else
				x = x->right;
		}
		ptr->parent = y;
		if (v < y->val)
			y->left = ptr;
		else
			y->right = ptr;
	}
	TreeNode* find(int x) const  // if tree has x, return ptr->val == x, else return nullptr 
	{
		TreeNode* ptr = root;
		while (ptr != nullptr)
		{
			if (x == ptr->val)
				return ptr;
			else if (x < ptr->val)
				ptr = ptr->left;
			else 
				ptr = ptr->right;
		}
		return ptr;
	}
	void erase(int x)
	{
		TreeNode* ptr = find(x);
		if (ptr == nullptr)  return;
		
		if (ptr->left == nullptr || ptr->right == nullptr)  // 1. has no child  2. has one child  merged.
		{
			if (ptr->parent == nullptr)  // ptr == root
			{
				if (ptr->left != nullptr)
					root = ptr->left;
				else if (ptr->right != nullptr)
					root = ptr->right;
				else
					root = nullptr;
			}
			else if (ptr == ptr->parent->left)
			{
				if (ptr->left != nullptr)
				{
					ptr->parent->left = ptr->left;
					ptr->left->parent = ptr->parent;
				}
				else if (ptr->right != nullptr)
				{
					ptr->parent->left = ptr->right;
					ptr->right->parent = ptr->parent;
				}
				else
					ptr->parent->left = nullptr;
			}
			else    // ptr == ptr->parent->right 
			{
				if (ptr->left != nullptr)
				{
					ptr->parent->right = ptr->left;
					ptr->left->parent = ptr->parent;
				}
				else if (ptr->right != nullptr) 
				{
					ptr->parent->right = ptr->right;
					ptr->right->parent = ptr->parent;
				}
				else 
					ptr->parent->right = nullptr;
			}
		}
		else   // 3. has two child
		{
			TreeNode* z = ptr->right;
			while (z->left != nullptr)
				z = z->left;
			if (z != ptr->right)
			{
				if (z->right != nullptr)
				{
					z->parent->left = z->right;
					z->right->parent = z->parent; 
				}
				else
					z->parent->left = nullptr;
			}
			else
				ptr->right == nullptr;

			if (ptr->parent == nullptr)  // ptr == root
			{
				root = z;
				z->parent = ptr->parent;
				z->left = ptr->left;
				z->right = ptr->right;
			}
			else if (ptr == ptr->parent->left)
			{
				ptr->parent->left = z;
				z->parent = ptr->parent;
				z->left = ptr->left;
				z->right = ptr->right;
			}
			else 
			{
				ptr->parent->right = z;
				z->parent = ptr->parent;
				z->left = ptr->left;
				z->right = ptr->right;
			}
		}
		delete ptr;
	}
	
	TreeNode* build_tree(int arr[], int sz)
	{
		for (int i = 0; i < sz; i++)
		{
			insert(arr[i]);		
		}
		return root;
	}
	void print(TreeNode* root) const
	{
		if (root == nullptr) return ;
		print(root->left);
		std::cout << root->val << " ";
		print(root->right);
	}
	TreeNode* get_root() const 
	{
		return root;
	}
private:
	TreeNode* root;

	TreeNode* new_node(int x)
	{
		TreeNode* ptr = new TreeNode;
		ptr->val = x;
		ptr->left = nullptr;
		ptr->right = nullptr;
		ptr->parent = nullptr;
	}
	void destroy_tree(TreeNode* root)
	{
		if (root == nullptr) return;
		destroy_tree(root->left);
		destroy_tree(root->right);
		delete root;
	}
};



















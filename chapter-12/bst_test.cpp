/*
 * Filename: bst.test.cpp 
 *
 */

#include "Binary_search_tree.h"

int main()
{
	int sz = 10, arr[sz] = {5,12,8,0,4,11,7,9,100,4};
	for (int i = 0; i < sz; ++i)  std::cout << arr[i] << " "; std::cout << std::endl;

	binary_search_tree bst;
	bst.build_tree(arr, sz);
	bst.print(bst.get_root());
	std::cout << std::endl;

	bst.insert(10000);
	bst.print(bst.get_root());
	std::cout << std::endl;

	bst.erase(100);
	bst.print(bst.get_root());
	std::cout << std::endl;
	return 0;
}





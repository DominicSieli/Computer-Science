#include <iostream>

#include "Binary_Search_Tree.h"

Data_Structures::Binary_Search_Tree<int> bst(10);

int main()
{
	bst.Insert(2);
	bst.Insert(20);
	bst.Insert(4);
	bst.Insert(16);
	bst.Print();

	std::cout << bst.Min() << '\n';
	std::cout << bst.Max() << '\n';
	std::cin.get();
}
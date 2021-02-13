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
	
	std::cout << '\n';
	
	bst.Remove(2);
	bst.Remove(20);
	bst.Print();
	
	std::cin.get();
}
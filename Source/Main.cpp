#include <vector>
#include <iomanip>
#include <iostream>

#include "Binary_Search_Tree.h"

Data_Structures::Binary_Search_Tree<int> bst;
std::vector<int> vector {12, 7, 16, 2, 20, 18, 19, 24};

int main()
{
	for(auto x : vector)
	{
		bst.Insert(x);
	}

	bst.Print();

	std::cout << '\n';

	for(auto x : vector)
	{
		bst.Remove(x);
	}

	bst.Print();

	std::cout << '\n';

	for(auto x : vector)
	{
		std::cout << "Contains " << x << ": " << std::boolalpha << bst.Contains(x) << '\n';
	}

	std::cin.get();
}
#include <iostream>

#include "Binary_Search_Tree.h"

Data_Structures::Binary_Search_Tree<int> bst(12);

int main()
{
	bst.Insert(7);
	bst.Insert(2);
	bst.Insert(20);
	bst.Insert(25);
	bst.Insert(67);
	bst.Insert(22);
	bst.Insert(13);

	bst.Print();

	std::cout << '\n';

	bst.Remove(20);

	std::cout << '\n';

	bst.Print();

	std::cout << '\n';

	std::cout << bst.Contains(20) << '\n';

	std::cout << '\n';

	std::cout << bst.Min_Value() << '\n';
	std::cout << bst.Max_Value() << '\n';

	std::cin.get();
}
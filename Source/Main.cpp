#include <iomanip>
#include <iostream>

#include "Binary_Search_Tree.h"

Data_Structures::Binary_Search_Tree<int> bst(12);

int main()
{
	//bst.Insert(2);
	//bst.Insert(7);
	//bst.Insert(20);
	//bst.Insert(25);
	//bst.Insert(67);
	//bst.Insert(22);
	//bst.Insert(13);

	bst.Print();

	std::cout << '\n';

	//bst.Remove(2);
	//bst.Remove(7);
	//bst.Remove(22);
	//bst.Remove(67);
	//bst.Remove(13);
	//bst.Remove(25);
	//bst.Remove(20);
	//bst.Remove(12);

	std::cout << '\n';

	bst.Print();

	std::cout << '\n';

	std::cout << "Min Value: " << bst.Min_Value() << '\n';
	std::cout << "Max Value: " << bst.Max_Value() << '\n';

	std::cout << '\n';

	std::cout << "Contains 12: " << std::boolalpha << bst.Contains(12) << '\n';

	std::cin.get();
}
#include <iostream>

#include "Single_Link_List.h"

Data_Structures::Single_Link_List<int> list1({1,2,3,4,5,6,7,8,9,10});
Data_Structures::Single_Link_List<int> list;

int main()
{
	list = list1;

	for(unsigned int i = 0; i < list.Count(); i++)
	{
		std::cout << list[i] << '\n';
	}

	std::cout << '\n';
	list.Reverse();

	for(unsigned int i = 0; i < list.Count(); i++)
	{
		std::cout << list[i] << '\n';
	}

	std::cin.get();
}
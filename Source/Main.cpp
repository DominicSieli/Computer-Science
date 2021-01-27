#include <iostream>

#include "Double_Link_List.h"

Data_Structures::Double_Link_List<int> list;

int main()
{
	for(int i = 0; i < 10; i++)
	{
		list.Insert_Head(i);
	}

	for(int i = 0; i < 10; i++)
	{
		std::cout << list.Get_Data(i) << '\n';
	}

	std::cout << '\n';
	list.Reverse();

	for(int i = 0; i < 10; i++)
	{
		std::cout << list.Get_Data(i) << '\n';
	}

	std::cin.get();
}
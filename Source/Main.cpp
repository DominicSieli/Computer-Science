#include <iostream>

#include "Single_Link_List.h"

Data_Structures::Single_Link_List<int> list({1,2,3,4,5,6,7,8,9,10});

void Print(Data_Structures::Single_Link_List<int>& list)
{
	for(unsigned int i = 0; i < list.Count(); i++)
	{
		std::cout << list[i] << '\n';
	}

	std::cout << '\n';
}

int main()
{
	Print(list);
	//list.Clear();
	list.Reverse();
	//list.Insert(0,32);
	//list.Insert(list.Count(),64);
	//list.Insert_Head(64);
	//list.Insert_Tail(555);
	//list.Delete(0);
	//list.Delete(list.Count() - 1);
	//std::cout << list.Contains(6);
	//list = {2,4,8,16,32,64};
	//list.Delete_Head();
	//list.Delete_Tail();
	//std::cout << list.Empty() << '\n';
	//std::cout << list.Count() << '\n';
    Print(list);

	std::cin.get();
}
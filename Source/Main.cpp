#include <iostream>

#include "Single_Link_List.h"

Data_Structures::Single_Link_List<int> linked_list;

int main()
{
	for(unsigned long long i = 0; i < 10; i++)
	{
		linked_list.Insert_Tail(i);
	}

	for(unsigned long long i = 0; i < linked_list.Count(); i++)
	{
		std::cout << linked_list.Get_Data(i) << '\n';
	}

	std::cout << '\n';
	//linked_list.Clear();
	linked_list.Insert(4, 2000);
	linked_list.Insert_Head(4000);
	linked_list.Insert_Tail(8000);

	for(unsigned long long i = 0; i < linked_list.Count(); i++)
	{
		std::cout << linked_list.Get_Data(i) << '\n';
	}

	std::cout << '\n';
	//linked_list.Clear();
	linked_list.Delete(4);
	linked_list.Delete_Head();
	linked_list.Delete_Tail();

	for(unsigned long long i = 0; i < linked_list.Count(); i++)
	{
		std::cout << linked_list.Get_Data(i) << '\n';
	}

	std::cout << '\n';

	std::cout << linked_list.Search(2000) << '\n';

	std::cin.get();
}
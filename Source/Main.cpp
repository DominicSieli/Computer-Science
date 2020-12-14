#include <iostream>

#include "Static_Array.h"

Data_Structures::Static_Array<int, 10> static_array({10,11,12,13,14,15,16,17,18,19,20,21,22});

int main()
{
	//static_array = {10,11,12,13,14,15,16,17,18,19,20,21,22};

	for(unsigned long long i = 0; i < static_array.Size(); i++)
	{
		std::cout << static_array[i] << '\n';
	}

	std::cout << '\n';

	//static_array.Clear();
	//static_array.Fill({});
	//static_array.Remove_Value(10);
	//static_array.Ordered_Remove(0);
	//static_array.Ordered_Remove_Value(10);

	for(unsigned long long i = 0; i < static_array.Count(); i++)
	{
		std::cout << static_array[i] << '\n';
	}

	std::cin.get();
}
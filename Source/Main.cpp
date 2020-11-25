#include <iostream>

#include "Static_Array.h"

DataStructures::Static_Array<short, 20> array;

int main()
{
	for(unsigned long long i = 0; i < array.Size(); i++)
	{
		array[i] = i;
	}

	for(unsigned long long i = 0; i < array.Size(); i++)
	{
		std::cout << array[i] << '\n';
	}

	std::cin.get();
}
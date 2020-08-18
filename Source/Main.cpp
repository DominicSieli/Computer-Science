#include <iostream>

#include "Dynamic_Array.h"

DataStructures::DynamicArray<int> array;

int main()
{
	for(unsigned long long i = 0; i < 10; i++)
	{
		array.Add((int)i);
	}

	for(unsigned long long i = 0; i < 10; i++)
	{
		std::cout << array[i] << '\n';
	}

	std::cin.get();
}
#include <iostream>

#include "Static_Array.h"

DataStructures::StaticArray<int, 10> staticArray;

int main()
{
	for(unsigned long long i = 0; i < staticArray.Size(); i++)
	{
		staticArray[i] = i;
	}

	for(unsigned long long i = 0; i < staticArray.Size(); i++)
	{
		std::cout << staticArray[i] << '\n';
	}

	std::cin.get();
}
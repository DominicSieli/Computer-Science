#include <iostream>

#include "Array.h"

int main()
{
	Array<int, 10> array;

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
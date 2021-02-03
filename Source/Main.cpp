#include <iostream>

#include "Vector.h"

Data_Structures::Vector<int> vector;

int main()
{
	for(unsigned long long i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i] << " ";
	}

	//vector.Sort();
	//vector.Reverse();
	std::cout << '\n';

	for(unsigned long long i = 0; i < vector.Count(); i++)
	{
		std::cout << vector[i] << " ";
	}

	std::cin.get();
}
#include <iostream>

#include "Node.h"

const unsigned int Size = 8;

DataStructures::Node<int, Size>* parent = new DataStructures::Node<int, Size>();

int main()
{
	std::cout << parent->data << '\n' << '\n';

	for(unsigned int i = 0; i < Size; i++)
	{
		std::cout << parent->link[i] << '\n';
	}

	std::cin.get();
}
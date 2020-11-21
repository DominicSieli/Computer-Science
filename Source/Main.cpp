#include <iostream>

#include "Node.h"

const unsigned int P = 8;

DataStructures::Node<int, P>* parent = new DataStructures::Node<int, P>();

int main()
{
	std::cout << parent->data << '\n' << '\n';

	for(unsigned int i = 0; i < P; i++)
	{
		std::cout << parent->pointers[i] << '\n';
	}

	std::cin.get();
}
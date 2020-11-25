#include <iostream>

#include "Node.h"

const unsigned long long links = 2;

DataStructures::Node<int, links>* node = new DataStructures::Node<int, links>(8);

int main()
{
	std::cout << "Node Data: " << node->data << "\n\n";

	for(unsigned long long i = 0; i < node->links.Size(); i++)
	{
		std::cout << "Link: " << i << " = " << node->links[i] << '\n';
	}

	std::cin.get();
}
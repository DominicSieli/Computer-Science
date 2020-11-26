#include <iostream>

#include "Node.h"

const unsigned long long links = 4;

DataStructures::Node<int, links>* child1 = new DataStructures::Node<int, links>(10, {nullptr, nullptr});
DataStructures::Node<int, links>* child2 = new DataStructures::Node<int, links>(10, {nullptr, nullptr});
DataStructures::Node<int, links>* child3 = new DataStructures::Node<int, links>(10, {nullptr, nullptr});
DataStructures::Node<int, links>* child4 = new DataStructures::Node<int, links>(10, {nullptr, nullptr});

DataStructures::Node<int, links>* node = new DataStructures::Node<int, links>();

int main()
{
	std::cout << "Node Data: " << node->data << "\n\n";

	for(unsigned long long i = 0; i < node->links.Size(); i++)
	{
		std::cout << "Link: " << i << " = " << node->links[i] << '\n';
	}

	std::cin.get();
}
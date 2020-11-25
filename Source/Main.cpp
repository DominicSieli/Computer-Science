#include <iostream>

#include "Node.h"

const unsigned short Size = 2;

DataStructures::Node<short, Size>* node = new DataStructures::Node<short, Size>();

int main()
{
	std::cout << "Data Size: " << sizeof(node->data) << '\n';
	std::cout << "Links Size: " << sizeof(node->link) << '\n';
	std::cout << "Node Size: " << sizeof(node->data) + sizeof(node->link) << '\n';
	std::cin.get();
}
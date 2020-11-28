#include <iostream>

#include "Node.h"

const unsigned long long links = 4;

Data_Structures::Node<int, links>* child1 = new Data_Structures::Node<int, links>(10, {nullptr, nullptr});
Data_Structures::Node<int, links>* child2 = new Data_Structures::Node<int, links>(10, {nullptr, nullptr});
Data_Structures::Node<int, links>* child3 = new Data_Structures::Node<int, links>(10, {nullptr, nullptr});
Data_Structures::Node<int, links>* child4 = new Data_Structures::Node<int, links>(10, {nullptr, nullptr});

Data_Structures::Node<int, links>* node = new Data_Structures::Node<int, links>();

int main()
{
	std::cout << "Node Data: " << node->data << "\n\n";

	for(unsigned long long i = 0; i < node->links.Size(); i++)
	{
		std::cout << "Link: " << i << " = " << node->links[i] << '\n';
	}

	std::cin.get();
}
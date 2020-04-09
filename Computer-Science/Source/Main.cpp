#include <iostream>

#include "DataStructures/Stacks/LinkedArrayStack.h"

int main()
{
	unsigned int nodes = 0;
	DataStructures::LinkedArrayStack<int> stack(0, 0);

	for(int i = 0; i < 20; i++)
	{
		stack.Push(i);
	}

	nodes =  stack.Nodes();

	while(stack.Nodes() > 0)
	{
		std::cout << stack.Pop() << std::endl;
	}

	if(stack.Nodes() == 0)
	{
		std::cout << std::endl;
		std::cout << "Stacks Used: " << nodes << std::endl;
		std::cout << "Stack Empty: " << stack.Nodes() << std::endl;
	}
}
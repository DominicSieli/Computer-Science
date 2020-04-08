#include <iostream>

#include "DataStructures/LinkedListStack.h"

int main()
{
	LinkedList::LinkedListStack<int> stack;

	while(stack.Nodes() < 10)
	{
		stack.Push(stack.Nodes());
	}

	while(stack.Nodes() > 0)
	{
		std::cout << stack.Pop() << std::endl;
	}
}
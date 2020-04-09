#include <iostream>

#include "DataStructures/LinkedArrayStack.h"

int main()
{
	DataStructures::LinkedArrayStack<int> stack(100);

	for(int i = 0; i < 100; i++)
	{
		stack.Push(i);
	}

	while(stack.Nodes() > 0)
	{
		std::cout << stack.Pop() << std::endl;
	}
}
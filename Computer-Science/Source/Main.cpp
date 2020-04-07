#include "Log.h"
#include "DataStructures/LinkedListStack.h"

int main()
{
	DataStructures::LinkedListStack<int> stack;

	for(int i = 0; i < 10; i++)
	{
		stack.Push(i);
	}

	for(int i = 0; i < 10; i++)
	{
		LOG(stack.Pop());
	}
}
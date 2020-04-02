#include "Log.h"
#include "DataStructures.h"

int main()
{
	DataStructures::Stack<int> stack(10);

	for(int i = 0; i < 10; i++)
	{
		stack.Push(i);
	}

	for(int i = 0; i < stack.Count(); i++)
	{
		std::cout << stack.Pop() << std::endl;
	}
	
	if(stack.Count() == 0)
	{
		LOG("Stack Is Empty")
	}
	else
	{
		LOG("Stack Is Not Empty")
	}
}
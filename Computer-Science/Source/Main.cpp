#include "Log.h"
#include "DataStructures/ArrayNodeStack.h"

int main()
{
	DataStructures::ArrayNodeStack<int> stack(10,10);

	for(int i = 0; i < 10; i++)
	{
		stack.Push(i);
	}

	while(stack.IsEmpty() == false)
	{
		std::cout << stack.Pop() << std::endl;
	}
	
	if(stack.IsEmpty() == true)
	{
		LOG("Stack Is Empty")
		std::cout << stack.Top() << std::endl;
	}
	else
	{
		LOG("Stack Is Not Empty")
	}
}
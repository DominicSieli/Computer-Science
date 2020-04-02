#include "Log.h"
#include "StackExample.h"

int main()
{
	Stack<int> stack(3);

	stack.Push(1);
	stack.Push(2);

	stack.Pop();
	stack.Pop();

	stack.Push(3);

	LOG("Top element is: " + stack.Peek())
	LOG("Stack size is " + stack.Size())

	stack.Pop();

	if(stack.IsEmpty() == true)
	{
		LOG("Stack Is Empty")
	}
	else
	{
		LOG("Stack Is Not Empty")
	}
}
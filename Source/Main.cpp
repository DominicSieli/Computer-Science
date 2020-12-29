#include <iostream>

#include "Deque.h"

Data_Structures::Deque<int> deque;

int main()
{
	for(int i = 0; i < 10; i++)
	{
		deque.Enqueue_Front(i);
	}

	while(!deque.Empty())
	{
		std::cout << deque.Dequeue_Front() << '\n';
	}

	std::cin.get();
}
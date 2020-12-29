#pragma once

#include "Node.h"

namespace Data_Structures
{
	template<typename T>
	class Stack
	{
	private:
	    Node<T, 1>* top = nullptr;
	    unsigned long long count = 0;

	public:
		Stack()
		{}

		~Stack()
		{}

		void Push(const T& data)
		{
			Node<T, 1>* node = new Node<T, 1>(data);
			node->links[0] = top;
			top = node;
			count++;
		}

	    T Pop()
		{
			if(count == 0)
			{
				return {};
			}
			
			T data = top->data;
			Node<T, 1>* node = top;
			top = top->links[0];
			delete node;
			count--;
			return data;
		}

		T Top() const
		{
			return top->data;
		}

		bool Empty() const
		{
			return count == 0;
		}
	};
}
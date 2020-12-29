#pragma once

#include "Node.h"

namespace Data_Structures
{
	template<typename T>
	class Queue
	{
	private:
	    Node<T, 1>* back = nullptr;
	    Node<T, 1>* front = nullptr;
	    unsigned long long count = 0;

	public:
		Queue()
		{}

		~Queue()
		{}

		void Enqueue(const T& data)
		{
			Node<T, 1>* node = new Node<T, 1>(data);
			
			if(count == 0)
			{
				node->links[0] = nullptr;
				front = node;
				back = front;
			}
			else
			{
				back->links[0] = node;
				back = node;
			}
			
			count++;
		}

	    T Dequeue()
		{
			if(count == 0)
			{
				return {};
			}
			
			T data = front->data;
			Node<T, 1>* node = front;
			front = front->links[0];
			delete node;
			count--;
			return data;
		}

		T Front() const
		{
			return front->data;
		}

		bool Empty() const
		{
			return count == 0;
		}
	};
}
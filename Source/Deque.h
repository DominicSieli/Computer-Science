#pragma once

#include "Node.h"

namespace Data_Structures
{
	template<typename T>
	class Deque
	{
	private:
	    Node<T, 2>* back = nullptr;
	    Node<T, 2>* front = nullptr;
	    unsigned long long count = 0;

	public:
		Deque()
		{}

		~Deque()
		{}

		void Enqueue_Back(const T& data)
		{
			if(count == 0)
			{
				Enqueue_Front(data);
				return;
			}
			
			Node<T, 2>* node = new Node<T, 2>(data);
			
			back->links[1] = node;
			node->links[0] = back;
			back = node;
			count++;
		}
		
		void Enqueue_Front(const T& data)
		{
			Node<T, 2>* node = new Node<T, 2>(data);
			node->links[1] = front;
			
			if(front != nullptr)
			{
				front->links[0] = node;
			}
			
			front = node;
			
			if(count == 0)
			{
				back = front;
			}
			
			count++;
		}
		
		T Dequeue_Back()
		{
			if(count == 0)
			{
				return {};
			}
			
			if(count == 1)
			{
				return Dequeue_Front();
			}
			
			T data = back->data;
			Node<T, 2>* node = back;
			back = back->links[0];
			back->links[1] = nullptr;
			delete node;
			count--;
			return data;
		}

	    T Dequeue_Front()
		{
			if(count == 0)
			{
				return {};
			}
			
			T data = front->data;
			Node<T, 2>* node = front;
			front = front->links[1];
			delete node;
			
			if(front != nullptr)
			{
				front->links[0] = nullptr;
			}
			
			count--;
			return data;
		}
		
		T Back() const
		{
			return back->data;
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
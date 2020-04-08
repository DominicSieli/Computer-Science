#pragma once

#include "LinkedListNode.h"

namespace LinkedList
{
	template<typename T>
	class LinkedListStack
	{
	private:
		unsigned int nodes = 0;
		Node<T>* topNode = nullptr;
		Node<T>* previousNode = nullptr;

	public:
		~LinkedListStack()
		{
			while(this->nodes > 0)
			{
				this->nodes--;
				this->previousNode = this->topNode->PreviousNode();
				delete this->topNode;
				this->topNode = this->previousNode;
			}
		}

		bool IsEmpty()
		{
			return this->nodes == 0;
		}

		void Push(const T& data)
		{
			this->nodes++;
			this->previousNode = this->topNode;
			Node<T>* newNode = new Node<T>(data, this->topNode);
			this->topNode = newNode;
		}

		T Pop()
		{
			this->nodes--;
			T data = this->topNode->Data();
			this->previousNode = this->topNode->PreviousNode();
			delete this->topNode;
			this->topNode = this->previousNode;
			return data;
		}

		T Top() const
		{
			return this->topNode->Data();
		}

		unsigned int Nodes() const
		{
			return this->nodes;
		}
	};
}
#pragma once

#include "DataStructures/Nodes/LinkedNode.h"

namespace DataStructures
{
	template<typename T>
	class LinkedListStack
	{
	private:
		unsigned int nodes = 0;
		LinkedNode<T>* currentNode = nullptr;
		LinkedNode<T>* previousNode = nullptr;

	public:
		~LinkedListStack()
		{
			while(this->nodes > 0)
			{
				this->nodes--;
				this->previousNode = this->currentNode->PreviousNode();
				delete this->currentNode;
				this->currentNode = this->previousNode;
			}
		}

		void Push(const T& data)
		{
			this->nodes++;
			this->previousNode = this->currentNode;
			LinkedNode<T>* newNode = new LinkedNode<T>(data, nullptr, this->currentNode);
			this->currentNode = newNode;
		}

		T Pop()
		{
			this->nodes--;
			T data = this->currentNode->Data();
			this->previousNode = this->currentNode->PreviousNode();
			delete this->currentNode;
			this->currentNode = this->previousNode;
			return data;
		}

		T Top() const
		{
			return this->currentNode->Data();
		}

		unsigned int Nodes() const
		{
			return this->nodes;
		}
	};
}
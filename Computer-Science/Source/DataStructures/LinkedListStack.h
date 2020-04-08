#pragma once

#include "DataStructures/LinkedNode.h"

namespace DataStructures
{
	template<typename T>
	class LinkedListStack
	{
	private:
		unsigned int nodes = 0;
		LinkedNode<T>* topNode = nullptr;
		LinkedNode<T>* previousNode = nullptr;

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

		void Push(const T& data)
		{
			this->nodes++;
			this->previousNode = this->topNode;
			LinkedNode<T>* newNode = new LinkedNode<T>(data, nullptr, this->topNode);
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

		bool IsEmpty() const
		{
			return this->nodes == 0;
		}
	};
}
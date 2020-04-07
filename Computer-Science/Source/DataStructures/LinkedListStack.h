#pragma once

#include "Log.h"
#include "Node.h"

namespace DataStructures
{
	template<typename T>
	class LinkedListStack
	{
	private:
		unsigned int count = 0;
		Node<T>* topNode = nullptr;
		Node<T>* previousNode = nullptr;

	public:
		LinkedListStack()
		{

		}

		~LinkedListStack()
		{
			for(unsigned int i = 0; i < this->count; i++)
			{
				if(this->topNode != nullptr)
				{
					this->previousNode = this->topNode;
					delete this->topNode;
					this->topNode = this->previousNode;
				}
			}
		}

		bool IsEmpty() const
		{
			return this->topNode == nullptr;
		}

		void Push(const T& value)
		{
			this->count++;
			this->previousNode = this->topNode;
			Node<T>* newNode = new Node<T>(value, this->topNode);
			this->topNode = newNode;
		}

		T Pop()
		{
			return this->topNode->Value();
			this->previousNode = this->topNode->PreviousNode();
			delete this->topNode;
			this->topNode = this->previousNode;
		}

		T Top() const
		{
			return this->topNode->Value();
		}
	};
}
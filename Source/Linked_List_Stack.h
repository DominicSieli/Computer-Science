#pragma once

#include "LinkedListNode.h"

namespace DataStructures
{
	template<typename T>
	class LinkedListStack
	{
	private:
		int index = 0;
		unsigned int nodes = 0;
		unsigned int initialSize = 0;
		unsigned int expansionSize = 0;
		LinkedListNode<T>* currentNode = nullptr;
		LinkedListNode<T>* previousNode = nullptr;

	public:
		LinkedListStack(const unsigned int& initialSize, const unsigned int& expansionSize) :
			index(0), nodes(0), initialSize(initialSize), expansionSize(expansionSize), currentNode(nullptr), previousNode(nullptr)
		{
			if(initialSize < 1)
			{
				this->initialSize = 1;
			}

			if(expansionSize < 1)
			{
				this->expansionSize = 1;
			}
		}

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
			this->index++;

			if(this->nodes == 0)
			{
				this->nodes++;
				this->index = 0;
				this->previousNode = this->currentNode;
				LinkedListNode<T>* newNode = new LinkedListNode<T>(initialSize, nullptr, this->currentNode);
				this->currentNode = newNode;
			}

			if(this->nodes > 0)
			{
				if(this->index > this->currentNode->Size() - 1)
				{
					this->nodes++;
					this->index = 0;
					this->previousNode = this->currentNode;
					LinkedListNode<T>* newNode = new LinkedListNode<T>(expansionSize, nullptr, this->currentNode);
					this->currentNode = newNode;
				}
			}

			this->currentNode->SetData(this->index, data);
		}

		T Pop()
		{
			T data;

			if(this->nodes > 0)
			{
				data = this->currentNode->GetData(this->index);
				this->index--;

				if(this->index < 0)
				{
					this->nodes--;
					this->previousNode = this->currentNode->PreviousNode();
					delete this->currentNode;
					this->currentNode = this->previousNode;

					if(this->currentNode != nullptr)
					{
						this->index = this->currentNode->Size() - 1;
					}
				}
			}

			return data;
		}

		T Top() const
		{
			return this->currentNode->GetData(this->index);
		}

		unsigned int Nodes() const
		{
			return this->nodes;
		}
	};
}
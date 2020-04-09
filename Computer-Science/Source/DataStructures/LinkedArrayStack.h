#pragma once

#include "DataStructures/LinkedArrayNode.h"

namespace DataStructures
{
	template<typename T>
	class LinkedArrayStack
	{
	private:
		int index = 0;
		unsigned int nodes = 0;
		unsigned int nodeSize = 0;
		LinkedArrayNode<T>* currentNode = nullptr;
		LinkedArrayNode<T>* previousNode = nullptr;

	public:
		LinkedArrayStack(unsigned int nodeSize) :
			index{ 0 },
			nodes{ 0 },
			nodeSize{ nodeSize },
			currentNode{ nullptr },
			previousNode{ nullptr }
		{

		}

		~LinkedArrayStack()
		{
			while(this->nodes > 0)
			{
				this->nodes--;
				this->previousNode = this->currentNode->PreviousNode();
				delete this->currentNode;
				this->currentNode = this->previousNode;
			}
		}

		void Push(const T& value)
		{
			this->index++;

			if(this->nodes == 0 || this->index > this->nodeSize - 1)
			{
				this->nodes++;
				this->index = 0;
				this->previousNode = this->currentNode;
				LinkedArrayNode<T>* newNode = new LinkedArrayNode<T>(nodeSize, nullptr, this->currentNode);
				this->currentNode = newNode;
			}

			this->currentNode->SetValue(this->index, value);
		}

		T Pop()
		{
			T data;

			if(this->nodes > 0)
			{
				data = this->currentNode->GetValue(this->index);
				this->index--;

				if(this->index < 0)
				{
					this->nodes--;
					this->index = this->nodeSize - 1;
					this->previousNode = this->currentNode->PreviousNode();
					delete this->currentNode;
					this->currentNode = this->previousNode;
				}
			}

			return data;
		}

		T Top() const
		{
			return this->currentNode->GetValue(this->index);
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
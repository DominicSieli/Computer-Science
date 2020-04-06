#pragma once

#include "NodeArray.h"

namespace DataStructures
{
	template<typename T>
	struct ArrayNodeStack
	{
	private:
		T* top = nullptr;
		unsigned int nodeCount = 0;
		unsigned int expansionSize = 0;
		ArrayNode<T> currentNode = nullptr;
		ArrayNode<T>* previousNode = nullptr;

	public:
		ArrayNodeStack(const unsigned int& size, const unsigned int& expansionSize)
		{
			this->nodeCount++;
			this->expansionSize = expansionSize;
			ArrayNode<T> currentNode = new ArrayNode<T>(size + 1, nullptr);
		}

		~ArrayNodeStack()
		{
			while(nodeCount > 0)
			{
				this->previousNode = this->currentNode.PreviousNode();

				this->nodeCount--;
				delete this->currentNode;
				this->currentNode = this->previousNode;
			}
		}

		bool IsEmpty() const
		{
			if(this->top == this->currentNode && this->currentNode.PreviousNode() != nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void Push(const T& item)
		{
			if(this->top < (this->currentNode.Array() += this->currentNode.Size()))
			{
				this->top++;
			}
			else
			{
				this->nodeCount++;
				ArrayNode<T> newNode = new ArrayNode<T>(this->expansionSize, this->currentNode);
				this->currentNode = newNode;
			}

			*this->top = item;
		}

		T Pop()
		{
			if(this->top > this->currentNode.Array())
			{
				this->top--;
				return *this->top;
			}

			if(this->top <= this->currentNode.Array() && this->currentNode.PreviousNode() != nullptr)
			{
				this->previousNode = this->currentNode.PreviousNode();
				
				this->nodeCount--;
				delete this->currentNode;
				this->currentNode = this->previousNode;
				this->top = (this->currentNode.Array() += this->currentNode.Size());

				return *this->top;
			}
		}

		T Top() const
		{
			return *this->top;
		}
	};
}
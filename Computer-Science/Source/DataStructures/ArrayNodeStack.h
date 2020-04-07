#pragma once

#include "Log.h"
#include "ArrayNode.h"

namespace DataStructures
{
	template<typename T>
	class NodeArrayStack
	{
	private:
		const unsigned int size = 0;
		unsigned int nodeCount = 0;
		T* topItemPointer = nullptr;
		ArrayNode<T>* currentNode = nullptr;
		ArrayNode<T>* previousNode = nullptr;

	public:
		NodeArrayStack(const unsigned int& size) :
			size{ size }
		{
			
		}

		~NodeArrayStack()
		{
			ArrayNode<T>* tempNode = nullptr;

			do
			{
				tempNode = this->previousNode;
				DeleteCurrentNode();
				this->currentNode = tempNode;
			}
			while(currentNode != nullptr);
		}

		void inline CreateNode()
		{
			this->nodeCount++;

			ArrayNode<T>* newNode = new ArrayNode<T>(this->size);

			this->previousNode = this->currentNode;
			this->currentNode = newNode;

			LOG("Node Created")
		}

		void inline DeleteCurrentNode()
		{
			delete this->currentNode;
			this->currentNode = this->previousNode;

			LOG("Current Node Deleted")
		}

		bool IsEmpty() const
		{
			return this->currentNode == nullptr;
		}

		void Push(const T& item)
		{
			if(this->currentNode == nullptr)
			{
				this->CreateNode();
			}

			if(this->topItemPointer < (this->currentNode->ArrayPointer() + this->size))
			{
				this->topItemPointer++;
			}
			else
			{
				CreateNode();
				this->topItemPointer = this->currentNode->ArrayPointer();
			}

			this->currentNode[this->topItemPointer - this->currentNode->ArrayPointer()] = item;
		}

		T Pop()
		{
			if(this->topItemPointer != nullptr)
			{
				if(this->topItemPointer > this->currentNode->ArrayPointer())
				{
					this->topItemPointer--;
					return *(this->topItemPointer);
				}
				else
				{
					DeleteCurrentNode();
					this->topItemPointer = (this->currentNode->ArrayPointer() + this->size);
					return *(this->topItemPointer);
				}
			}
		}

		T Top() const
		{
			return *(this->topItemPointer);
		}
	};
}
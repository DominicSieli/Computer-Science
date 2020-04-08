#pragma once

namespace LinkedList
{
	template<typename T>
	struct Node
	{
		T data;
		Node* previousNode = nullptr;

		Node(const T& data, Node* previousNode) :
			data{ data },
			previousNode{ previousNode }
		{

		}

		~Node()
		{

		}

		T Data() const
		{
			return this->data;
		}

		Node* PreviousNode() const
		{
			return this->previousNode;
		}
	};
}
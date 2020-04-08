#pragma once

namespace LinkedList
{
	template<typename T>
	struct Node
	{
	private:
		T data;
		Node<T>* previousNode = nullptr;

	public:
		Node(const T& data, Node<T>* previousNode) :
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

		Node<T>* PreviousNode() const
		{
			return this->previousNode;
		}
	};
}
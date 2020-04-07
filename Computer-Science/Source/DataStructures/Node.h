#pragma once

namespace DataStructures
{
	template<typename T>
	struct Node
	{
	private:
		T value;
		Node<T>* previousNode = nullptr;

	public:
		Node(const T& value, Node<T>* previousNode) :
			value{ value },
			previousNode{ previousNode }
		{

		}

		~Node()
		{
			
		}

		T& Value()
		{
			return this->value;
		}

		Node<T>* PreviousNode() const
		{
			return this->previousNode;
		}
	};
}
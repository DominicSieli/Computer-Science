#pragma once

namespace DataStructures
{
	template <typename T>
	struct Node
	{
	private:
		T data;
		Node<T> *nextNode = nullptr;
		Node<T> *previousNode = nullptr;

	public:
		Node(const T &data, Node<T> *nextNode, Node<T> *previousNode) :
			data{data}, nextNode{nextNode}, previousNode{previousNode}
		{
		}

		T Data() const
		{
			return this->data;
		}

		Node<T> *NextNode() const
		{
			return this->nextNode;
		}

		Node<T> *PreviousNode() const
		{
			return this->previousNode;
		}
	};
}
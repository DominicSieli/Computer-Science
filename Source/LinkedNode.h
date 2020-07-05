#pragma once

namespace DataStructures
{
	template <typename T>
	struct LinkedNode
	{
	private:
		T data;
		LinkedNode<T> *nextNode = nullptr;
		LinkedNode<T> *previousNode = nullptr;

	public:
		LinkedNode(const T &data, LinkedNode<T> *nextNode, LinkedNode<T> *previousNode) : data{data},
																						  nextNode{nextNode},
																						  previousNode{previousNode}
		{
		}

		T Data() const
		{
			return this->data;
		}

		LinkedNode<T> *NextNode() const
		{
			return this->nextNode;
		}

		LinkedNode<T> *PreviousNode() const
		{
			return this->previousNode;
		}
	};
} // namespace DataStructures
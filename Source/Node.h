#pragma once

namespace DataStructures
{
	template <typename T>
	struct Node
	{
	private:
		T data;
		Node<T> *node = nullptr;
		Node<T> *nextNode = nullptr;
		Node<T> *previousNode = nullptr;

	public:
		Node(const T &data, const Node<T> *nextNode, const Node<T> *previousNode) :
			data(data), node(this), nextNode(nextNode), previousNode(previousNode)
		{

		}

		void SetData(const T &data) noexcept
		{
			this->data = data;
		}

		const T GetData() const noexcept
		{
			return this->data;
		}

		const Node<T> *Node() const noexcept
		{
			return this->Node;
		}

		const Node<T> *NextNode() const noexcept
		{
			return this->nextNode;
		}

		const Node<T> *PreviousNode() const noexcept
		{
			return this->previousNode;
		}
	};
}
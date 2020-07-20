#pragma once

namespace DataStructures
{
	template <typename T>
	struct VectorNode
	{
	private:
		T *node = nullptr;
		unsigned int size = 0;
		VectorNode *nextNode = nullptr;
		VectorNode *previousNode = nullptr;

	public:
		VectorNode(const unsigned int &size, VectorNode<T> *nextNode, VectorNode<T> *previousNode) :
			node(new T[size]), size(size), nextNode(nextNode), previousNode(previousNode)
		{

		}

		~VectorNode()
		{
			delete[] this->node;
		}

		unsigned int Size() const
		{
			return this->size;
		}

		VectorNode<T> *NextNode() const
		{
			return this->nextNode;
		}

		VectorNode<T> *PreviousNode() const
		{
			return this->previousNode;
		}

		T GetData(const unsigned int &index) const
		{
			return this->node[index];
		}

		void SetData(const unsigned int &index, const T &data)
		{
			this->node[index] = data;
		}
	};
}
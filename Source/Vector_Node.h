#pragma once

namespace Data_Structures
{
	template <typename T>
	struct Vector_Node
	{
	private:
		T *node = nullptr;
		unsigned int size = 0;
		Vector_Node *nextNode = nullptr;
		Vector_Node *previousNode = nullptr;

	public:
		Vector_Node(const unsigned int &size, Vector_Node<T> *nextNode, Vector_Node<T> *previousNode) :
			node(new T[size]), size(size), nextNode(nextNode), previousNode(previousNode)
		{

		}

		~Vector_Node()
		{
			delete[] this->node;
		}

		unsigned int Size() const
		{
			return this->size;
		}

		Vector_Node<T> *NextNode() const
		{
			return this->nextNode;
		}

		Vector_Node<T> *PreviousNode() const
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
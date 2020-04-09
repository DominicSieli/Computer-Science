#pragma once

namespace DataStructures
{
	template<typename T>
	struct LinkedArrayNode
	{
	private:
		T* data = nullptr;
		unsigned int size = 0;
		LinkedArrayNode* nextNode = nullptr;
		LinkedArrayNode* previousNode = nullptr;

	public:
		LinkedArrayNode(const unsigned int& size, LinkedArrayNode<T>* nextNode, LinkedArrayNode<T>* previousNode) :
			data{ new T[size] },
			size{ size },
			nextNode{ nextNode },
			previousNode{ previousNode }
		{

		}

		~LinkedArrayNode()
		{
			delete[] this->data;
		}

		unsigned int Size() const
		{
			return this->size;
		}

		LinkedArrayNode<T>* NextNode() const
		{
			return this->nextNode;
		}

		LinkedArrayNode<T>* PreviousNode() const
		{
			return this->previousNode;
		}

		T GetData(const unsigned int& index) const
		{
			return this->data[index];
		}

		void SetData(const unsigned int& index, const T& data)
		{
			this->data[index] = data;
		}
	};
}
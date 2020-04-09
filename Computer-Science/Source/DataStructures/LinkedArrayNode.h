#pragma once

namespace DataStructures
{
	template<typename T>
	struct LinkedArrayNode
	{
	private:
		T* arrayNode = nullptr;
		LinkedArrayNode* nextNode = nullptr;
		LinkedArrayNode* previousNode = nullptr;

	public:
		LinkedArrayNode(const unsigned int& size, LinkedArrayNode<T>* nextNode, LinkedArrayNode<T>* previousNode) :
			arrayNode{ new T[size] },
			nextNode{ nextNode },
			previousNode{ previousNode }
		{

		}

		~LinkedArrayNode()
		{
			delete[] this->arrayNode;
		}

		LinkedArrayNode<T>* NextNode() const
		{
			return this->nextNode;
		}

		LinkedArrayNode<T>* PreviousNode() const
		{
			return this->previousNode;
		}

		T GetValue(const unsigned int& index) const
		{
			return this->arrayNode[index];
		}

		void SetValue(const unsigned int& index, const T& value)
		{
			this->arrayNode[index] = value;
		}
	};
}
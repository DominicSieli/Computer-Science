#pragma once

namespace DataStructures
{
	template<typename T>
	struct ArrayNode
	{
		const unsigned int size = 0;

		const T* array = nullptr;
		const T* previousArray = nullptr;

		ArrayNode(const unsigned int& size, const T* previousArray) :
			size{ size },
			array{ new T[size] },
			previousArray{ previousArray }
		{

		}

		~ArrayNode
		{
			delete[] this->array;
		}
	};

	template<typename T>
	struct ArrayNodeStack
	{
	private:
		T* currentNode = nullptr;
		unsigned int count = 0;
		unsigned int nodeCount = 0;

	public:
		ArrayNodeStack(const unsigned int& size)
		{
			nodeCount++;
			ArrayNode<T> node(size, nullptr);
			currentNode = node;
		}

		~ArrayNodeStack()
		{
			while(nodeCount > 0)
			{
				previousNode = currentNode->previousNode;
				delete currentNode;
			}
		}

		bool IsEmpty() const
		{
			return this->count == 0;
		}

		void Push(const T& item)
		{
			this->count++;

			if (this->count + 1 > this->size)
			{
				this->size++;
				T* newArray = new T[this->size];
				memcpy(newArray, this->stack, this->count * sizeof(T));

				delete[] this->stack;
				this->stack = newArray;
			}

			this->stack[this->count] = item;
		}

		T Pop()
		{
			return this->stack[this->count--];
		}

		T Top() const
		{
			return this->stack[this->count];
		}
	};
}
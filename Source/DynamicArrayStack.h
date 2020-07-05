#pragma once

#include <memory>

namespace DataStructures
{
	template <typename T>
	struct DynamicArrayStack
	{
	private:
		T *stack = nullptr;
		unsigned int size = 0;
		unsigned int count = 0;

	public:
		DynamicArrayStack(const unsigned int &size) : stack{new T[size + 1]},
													  size{size + 1}
		{
		}

		~DynamicArrayStack()
		{
			delete[] this->stack;
		}

		bool IsEmpty() const
		{
			return this->count == 0;
		}

		void Push(const T &item)
		{
			this->count++;

			if (this->count + 1 > this->size)
			{
				this->size++;
				T *newStack = new T[this->size];
				memcpy(newStack, this->stack, this->count * sizeof(T));

				delete[] this->stack;
				this->stack = newStack;
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
} // namespace DataStructures
#pragma once

#include <memory>

namespace Data_Structures
{
	template <typename T>
	struct Dynamic_Array_Stack
	{
	private:
		T *stack = nullptr;
		unsigned int size = 0;
		unsigned int count = 0;

	public:
		Dynamic_Array_Stack(const unsigned int &size)
			: stack(new T[size + 1]), size(size + 1)
		{

		}

		~Dynamic_Array_Stack()
		{
			delete[] stack;
			stack = nullptr;
		}

		bool IsEmpty() const
		{
			return count == 0;
		}

		void Push(const T &data)
		{
			count++;

			if (count + 1 > size)
			{
				size++;
				T *newStack = new T[size];
				memcpy(newStack, stack, count * sizeof(T));

				delete[] stack;
				stack = newStack;
			}

			stack[count] = data;
		}

		T Pop()
		{
			return stack[count--];
		}

		T Top() const
		{
			return stack[count];
		}
	};
}
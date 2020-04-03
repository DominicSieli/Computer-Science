#pragma once

#include <memory>

namespace DataStructures
{
	template<typename T>
	struct DynamicArrayStack
	{
		T* stack = nullptr;
		unsigned int size = 0;
		unsigned int count = 0;

		DynamicArrayStack(const unsigned int& n) :
			stack{ new T[n + 1] },
			size{ n + 1 }
		{
			
		}

		~DynamicArrayStack()
		{
			delete[] stack;
		}

		bool IsEmpty() const
		{
			return count == 0;
		}

		void Push(const T& element)
		{
			count++;

			if(count + 1 > size)
			{
				size++;
				T* newStack = new T[size];
				memcpy(newStack, stack, count * sizeof(T));

				delete[] stack;
				stack = newStack;
			}

			stack[count] = element;
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
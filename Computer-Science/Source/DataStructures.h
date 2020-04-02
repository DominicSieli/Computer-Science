#pragma once

#include <memory>

namespace DataStructures
{
	template<typename T>
	struct Stack
	{
		T* stack = nullptr;
		unsigned int size = 0;
		unsigned int count = 0;

		Stack(const unsigned int& n) :
			stack{ new T[n] },
			size{ n },
			count{ 0 }
		{

		}

		~Stack()
		{
			delete[] stack;
		}

		unsigned int Count() const
		{
			return count;
		}

		void Push(const T& element)
		{
			count++;

			if(count > size)
			{
				size++;
				T* newStack = new T[size];
				memcpy(newStack, stack, count * sizeof(T));

				delete[] stack;
				stack = newStack;
			}

			stack[count - 1] = element;
		}

		T Pop()
		{
			if(count > 0)
			{
				count--;
				return stack[count + 1];
			}
		}

		T Top() const
		{
			if(count > 0)
			{
				return stack[count];
			}
		}
	};
}
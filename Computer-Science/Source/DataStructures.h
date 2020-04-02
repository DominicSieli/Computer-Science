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
			delete[] this->stack;
		}

		unsigned int Count() const
		{
			return this->count;
		}

		void Push(const T& v)
		{
			this->count++;

			if (this->count > this->size)
			{
				this->size++;
				T* newStack = new T[this->size];
				memcpy(newStack, this->stack, this->count * sizeof(T));

				delete[] this->stack;
				this->stack = newStack;
			}

			this->stack[this->count - 1] = v;
		}

		T Pop()
		{
			count--;
			return this->stack[count];
		}

		T TopElement() const
		{
			if(this->count == 0)
			{
				return this->stack[0];
			}
			else
			{
				return this->stack[this->count - 1];
			}
		}
	};
}
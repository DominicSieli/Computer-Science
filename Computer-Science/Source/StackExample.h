#pragma once

#include "Log.h"

template<typename T>
struct Stack
{
private:
	int top;
	T* stack;
	unsigned int size;

public:
	Stack(unsigned int n):
		top{ -1 },
		stack{ new T[n] },
		size{ n }
	{

	}
	
	~Stack()
	{
		delete this->stack;
	}

	void Push(T value)
	{
		if(IsFull() == true)
		{
			LOG_ERROR("Stack OverFlow!")
		}
		else
		{
			LOG("Inserting " + value)
			this->stack[++this->top] = value;
		}
	}

	T Pop()
	{
		if(IsEmpty())
		{
			LOG_ERROR("Stack UnderFlow!")
		}

		LOG("Removing " + Peek())
		return this->stack[this->top--];
	}


	T Peek()
	{
		if(IsEmpty() == false)
		{
			return this->stack[this->top];
		}
	}

	unsigned int Size() const
	{
		return this->top + 1;
	}

	bool IsEmpty() const
	{
		return Size() == 0;
	}

	bool IsFull() const
	{
		return Size() == this->size;
	}
};
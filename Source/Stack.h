#pragma once

namespace Data_Structures
{
	template<typename T>
	class Stack
	{
	private:
		struct Node
		{
			T data {};
			Node* next = nullptr;

			Node(const T& data = {}, Node* next = nullptr) : data{data}, next{next}
			{}
		};

		Node* top = nullptr;
		unsigned long long count = 0;

	public:
		Stack()
		{}

		~Stack()
		{
			Clear();
		}

		void Push(const T& data) noexcept
		{
			count++;
			Node* node = new Node(data, top);
			top = node;
		}

		T Pop() noexcept
		{
			if(top != nullptr)
			{
				count--;
				T data = top->data;
				Node* node = top;
				top = top->next;
				delete node;
				return data;
			}

			return {};
		}

		T Top() const noexcept
		{
			return top->data;
		}

		bool Empty() const noexcept
		{
			return top == nullptr;
		}

		void Clear() noexcept
		{
			while(top != nullptr)
			{
				count--;
				Node* node = top;
				top = top->next;
				delete node;
			}
		}
	};
}
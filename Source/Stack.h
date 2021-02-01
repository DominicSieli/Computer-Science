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

			Node(const T& data) : data{data}
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
			Node* node = new Node(data);
			node->next = top;
			top = node;
			count++;
		}

		T Pop() noexcept
		{
			if(top == nullptr)
			{
				return {};
			}

			T data = top->data;
			Node* node = top;
			top = top->next;
			delete node;
			count--;
			return data;
		}

		T Top() const noexcept
		{
			return top->data;
		}

		bool Empty() const noexcept
		{
			return count == 0;
		}

		void Clear() noexcept
		{
			while(top != nullptr)
			{
				Node* node = top;
				top = top->next;
				delete node;
				count--;
			}
		}
	};
}
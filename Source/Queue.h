#pragma once

namespace Data_Structures
{
	template<typename T>
	class Queue
	{
	private:
		struct Node
		{
			T data {};
			Node* next = nullptr;

			Node(const T& data = {}, Node* next = nullptr) : data{data}, next{next}
			{}
		};

	    Node* back = nullptr;
	    Node* front = nullptr;
	    unsigned long long count = 0;

	public:
		Queue()
		{}

		~Queue()
		{
			Clear();
		}

		void Enqueue(const T& data) noexcept
		{
			count++;
			Node* node = new Node(data);

			if(front == nullptr)
			{
				node->next = nullptr;
				front = node;
				back = node;
			}
			else
			{
				back->next = node;
				back = node;
			}
		}

	    T Dequeue() noexcept
		{
			if(front != nullptr)
			{
				count--;
				T data = front->data;
				Node* node = front;
				front = front->next;
				delete node;
				return data;
			}

			return {};
		}

		T Front() const noexcept
		{
			return front->data;
		}

		bool Empty() const noexcept
		{
			return front == nullptr;
		}

		void Clear() noexcept
		{
			while(front != nullptr)
			{
				count--;
				Node* node = front;
				front = front->next;
				delete node;
			}
		}
	};
}
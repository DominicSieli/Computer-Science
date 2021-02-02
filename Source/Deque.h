#pragma once

namespace Data_Structures
{
	template<typename T>
	class Deque
	{
	private:
		struct Node
		{
			T data {};
			Node* next = nullptr;
			Node* previous = nullptr;

			Node(const T& data = {}, Node* next = nullptr, Node* previous = nullptr) : data{data}, next{next}, previous{previous}
			{}
		};

	    Node* back = nullptr;
	    Node* front = nullptr;
	    unsigned long long count = 0;

	public:
		Deque()
		{}

		~Deque()
		{
			Clear();
		}

		void Enqueue_Back(const T& data) noexcept
		{
			if(front == nullptr)
			{
				Enqueue_Front(data);
				return;
			}

			count++;
			Node* node = new Node(data, nullptr, back);
			back->next = node;
			back = node;
		}

		void Enqueue_Front(const T& data) noexcept
		{
			count++;
			Node* node = new Node(data, front, nullptr);

			if(front != nullptr)
			{
				front->previous = node;
			}

			front = node;

			if(back == nullptr)
			{
				back = front;
			}
		}

		T Dequeue_Back() noexcept
		{
			if(front == nullptr)
			{
				return {};
			}

			if(count == 1)
			{
				return Dequeue_Front();
			}

			count--;
			Node* node = back;
			T data = back->data;
			back = back->previous;
			back->next = nullptr;
			delete node;
			return data;
		}

	    T Dequeue_Front() noexcept
		{
			if(front == nullptr)
			{
				return {};
			}

			count--;
			Node* node = front;
			T data = front->data;
			front = front->next;

			if(front != nullptr)
			{
				front->previous = nullptr;
			}

			delete node;
			return data;
		}

		T Back() const noexcept
		{
			return back->data;
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
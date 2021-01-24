#pragma once

namespace Data_Structures
{
	template<typename T>
	class Double_Link_List
	{
	private:
		unsigned long long count = 0;

		struct Node
		{
			T data {};
			Node* next = nullptr;
			Node* previous = nullptr;

			Node(const T& data = {}) : data{data}
			{}
		};

	public:
		Node* head = nullptr;
		Node* tail = nullptr;

		Double_Link_List()
		{}

		~Double_Link_List()
		{}

		void Clear()
		{
			while(count > 0)
			{
				Delete_Head();
			}
		}

		unsigned long long Search(const T& data)
		{
			if(count == 0)
			{
				return 0;
			}

			unsigned long long index = 0;

			Node* node = head;

			while(node->data != data)
			{
				if(node == nullptr)
				{
					return 0;
				}

				index++;
				node = node->next;
			}

			return index;
		}

		void Delete_Head()
		{
			if(count == 0)
			{
				return;
			}

			Node* node = head;
			head = head->next;
			delete node;
			count--;

			if(count <= 1)
			{
				tail = head;
			}
		}

		void Delete_Tail()
		{
			if(count == 0)
			{
				return;
			}

			if(count == 1)
			{
				Delete_Head();
				return;
			}

			Node* tail_pointer = tail;
			tail = tail->previous;
			tail->next = nullptr;
			delete tail_pointer;
			count--;

			if(count <= 1)
			{
				tail = head;
			}
		}

		unsigned long long Count()
		{
			return count;
		}

		void Delete(const unsigned long long& index)
		{
			if(count == 0)
			{
				return;
			}

			if(index < 0 || index > count)
			{
				return;
			}

			if(index == 0)
			{
				Delete_Head();
				return;
			}

			if(index == count - 1)
			{
				Delete_Tail();
				return;
			}

			Node* previous_node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				previous_node = previous_node->next;
			}

			Node* node = previous_node->next;
			Node* next_node = node->next;
			previous_node->next = next_node;
			next_node->previous = previous_node;
			delete node;
			count--;

			if(count <= 1)
			{
				tail = head;
			}
		}

		void Insert_Head(const T& data)
		{
			Node* node = new Node(data);

			if(count > 0)
			{
				node->next = head;
				head->previous = node;
			}

			head = node;
			count++;

			if(count <= 1)
			{
				tail = head;
			}
		}

		void Insert_Tail(const T& data)
		{
			if(count == 0)
			{
				Insert_Head(data);
				return;
			}

			Node* node = new Node(data);
			tail->next = node;
			node->previous = tail;
			tail = node;
			count++;

			if(count <= 1)
			{
				tail = head;
			}
		}

		void Insert(const unsigned long long& index, const T& data)
		{
			if(index < 0 || index > count)
			{
				return;
			}

			if(index == 0)
			{
				Insert_Head(data);
				return;
			}
			else if(index == count)
			{
				Insert_Tail(data);
				return;
			}

			Node* previous_node = head;

			for(unsigned long long i = 0; i < index - 1; ++i)
			{
				previous_node = previous_node->next;
			}

			Node* next_node = previous_node->next;
			Node* node = new Node(data);
			node->next = next_node;
			node->previous = previous_node;
			previous_node->next = node;
			next_node->previous = node;
			count++;

			if(count <= 1)
			{
				tail = head;
			}
		}

		T Get_Data(const unsigned long long& index)
		{
			if(index < 0 || index > count)
			{
				return {};
			}

			Node* node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				node = node->next;
			}

			return node->data;
		}

		Node* Get_Address(const unsigned long long& index)
		{
			if(index < 0 || index > count)
			{
				return nullptr;
			}

			Node* node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				node = node->next;
			}

			return node;
		}

		void Reverse()
		{
			Node* left = head;
			Node* right = tail;

			while(left != right && left->next != right)
			{
				std::swap(left->data, right->data);
				left = left->next;
				right = right->previous;
			}
		}
	};
}
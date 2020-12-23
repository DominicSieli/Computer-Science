#pragma once

#include "Node.h"

namespace Data_Structures
{
	template<typename T, unsigned short N>
	class Linked_List
	{
	private:
		unsigned long long count {};

	public:
		Node<T, N>* head {};
		Node<T, N>* tail {};

	public:
		Linked_List()
		{}

		~Linked_List()
		{}

		void Clear()
		{
			while(count != 0)
			{
				Delete_Head();
			}
		}

		T Search(const T& data)
		{
			if(count == 0)
			{
				return {};
			}

			unsigned long long index = 0;

			Node<T, N>* node = head;

			while(node->data != data)
			{
				index++;
				node = node->links[0];

				if(node == nullptr)
				{
					return {};
				}
			}

			return index;
		}

		void Delete_Head()
		{
			if(count == 0)
			{
				return;
			}

			Node<T, N>* node = head;
			head = head->links[0];

			delete node;
			count--;
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

			Node<T, N>* previous_node = head;

			Node<T, N>* node = head->links[0];

			while(node->links[0] != nullptr)
			{
				previous_node = previous_node->links[0];
				node = node->links[0];
			}

			previous_node->links[0] = nullptr;
			tail = previous_node;

			delete node;
			count--;
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

			Node<T, N>* previous_node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				previous_node = previous_node->links[0];
			}

			Node<T, N>* node = previous_node->links[0];
			Node<T, N>* next_node = node->links[0];
			previous_node->links[0] = next_node;
			delete node;
			count--;
		}

		void Insert_Head(const T& data)
		{
			Node<T, N>* node = new Node<T, N>(data);

			node->links[0] = head;

			head = node;

			if(count == 0)
			{
				tail = head;
			}

			count++;
		}

		void Insert_Tail(const T& data)
		{
			if(count == 0)
			{
				Insert_Head(data);
				return;
			}

			Node<T, N>* node = new Node<T, N>(data);

			tail->links[0] = node;

			tail = node;

			count++;
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

			Node<T, N>* previous_node = head;

			for(unsigned long long i = 0; i < index - 1; ++i)
			{
				previous_node = previous_node->links[0];
			}

			Node<T, N>* next_node = previous_node->links[0];

			Node<T, N>* node = new Node<T, N>(data);

			node->links[0] = next_node;

			previous_node->links[0] = node;

			count++;
		}

		T Get_Data(const unsigned long long& index)
		{
			if(index < 0 || index > count)
			{
				return {};
			}

			Node<T, N>* node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				node = node->links[0];
			}

			return node->data;
		}

		Node<T, N>* Get_Address(const unsigned long long& index)
		{
			if(index < 0 || index > count)
			{
				return nullptr;
			}

			Node<T, N>* node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				node = node->links[0];
			}

			return node;
		}
	};
}
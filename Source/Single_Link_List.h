#pragma once

#include "Node.h"

namespace Data_Structures
{
	template<typename T>
	class Single_Link_List
	{
	private:
	    unsigned long long count = 0;
	    static const unsigned short Links = 1;

	public:
		Node<T, Links>* head = nullptr;
		Node<T, Links>* tail = nullptr;

	public:
		Single_Link_List()
		{}

		~Single_Link_List()
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

			Node<T, Links>* node = head;

			while(node->data != data)
			{
				index++;
				node = node->links[0];

				if(node == nullptr)
				{
					return 0;
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

			Node<T, Links>* node = head;
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

			Node<T, Links>* previous_node = head;
			Node<T, Links>* node = head->links[0];

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

			Node<T, Links>* previous_node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				previous_node = previous_node->links[0];
			}

			Node<T, Links>* node = previous_node->links[0];
			Node<T, Links>* next_node = node->links[0];
			previous_node->links[0] = next_node;
			delete node;
			count--;
		}

		void Insert_Head(const T& data)
		{
			Node<T, Links>* node = new Node<T, Links>(data);
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

			Node<T, Links>* node = new Node<T, Links>(data);
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

			Node<T, Links>* previous_node = head;

			for(unsigned long long i = 0; i < index - 1; ++i)
			{
				previous_node = previous_node->links[0];
			}

			Node<T, Links>* next_node = previous_node->links[0];
			Node<T, Links>* node = new Node<T, Links>(data);
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

			Node<T, Links>* node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				node = node->links[0];
			}

			return node->data;
		}

		Node<T, Links>* Get_Address(const unsigned long long& index)
		{
			if(index < 0 || index > count)
			{
				return nullptr;
			}

			Node<T, Links>* node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				node = node->links[0];
			}

			return node;
		}
	};
}
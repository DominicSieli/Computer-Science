#pragma once

#include "Single_Linked_Node.h"

namespace Data_Structures
{
	template<typename T>
	class Single_Linked_List
	{
	private:
		unsigned long long count {};

	public:
		Single_Linked_Node<T>* head {};
		Single_Linked_Node<T>* tail {};

	public:
		Single_Linked_List()
		{}

		~Single_Linked_List()
		{}

		void Clear()
		{

		}

		void Search(const T& data)
		{

		}

		void Delete_Head()
		{

		}

		void Delete_Tail()
		{

		}

		unsigned long long Count()
		{

		}

		void Delete(const unsigned long long& index)
		{

		}

		void Insert_Head(const T& data)
		{
			Single_Linked_Node<T>* node = new Single_Linked_Node<T>(data);

			node->next = head;

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

			Single_Linked_Node<T>* node = new Single_Linked_Node<T>(data);

			tail->next = node;

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

			Single_Linked_Node<T>* previous_node = head;

			for(unsigned long long i = 0; i < index - 1; ++i)
			{
				previous_node = previous_node->next;
			}

			Single_Linked_Node<T>* next_node = previous_node->next;

			Single_Linked_Node<T>* node = new Single_Linked_Node<T>(data);

			node->next = next_node;

			previous_node->next = node;

			count++;
		}

		Single_Linked_Node<T>* Get(const unsigned long long& index)
		{
			if(index < 0 || index > count)
			{
				return nullptr;
			}

			Single_Linked_List<T>* node = head;

			for(unsigned long long i = 0; i < index; ++i)
			{
				node = node->next;
			}

			return node;
		}
	};
}
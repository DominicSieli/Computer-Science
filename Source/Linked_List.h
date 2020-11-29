#pragma once

#include "Node.h"

namespace Data_Structures
{
	template<typename Data_Type, const unsigned long long Links>
	class Linked_List
	{
	private:
		Data_Structures::Node<Data_Type, Links>* head = nullptr;
		Data_Structures::Node<Data_Type, Links>* tail = nullptr;
		Data_Structures::Node<Data_Type, Links>* pointer = nullptr;

	public:
		Linked_List() {}

		~Linked_List()
		{
			while()
			{

			}
		}

		void Add_Head(const Data_Type& data)
		{

		}

		void Add_Tail(const Data_Type& data)
		{

		}

		void Ordered_Add(const Data_Type& data)
		{

		}

		void Delete_All(const Data_Type& data)
		{

		}

		void Delete_First(const Data_Type& data)
		{

		}
	};
}
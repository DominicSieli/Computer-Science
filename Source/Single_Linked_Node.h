#pragma once

namespace Data_Structures
{
	template<typename T>
	struct Single_Linked_Node
	{
		T data {};
		Single_Linked_Node<T>* next {};

		Single_Linked_Node(const T& data = {}, Single_Linked_Node<T>* next = {})
			: data{data}, next{next}
		{}
	};
}
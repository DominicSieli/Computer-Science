#pragma once

namespace Data_Structures
{
	template<typename T>
	struct Double_Linked_Node
	{
		T data {};
		Double_Linked_Node<T>* next {};
		Double_Linked_Node<T>* previous {};

		Double_Linked_Node(const T& data = {}, Double_Linked_Node<T>* next = {}, Double_Linked_Node<T>* previous = {})
			: data{data}, next{next}, previous{previous}
		{}
	};
}
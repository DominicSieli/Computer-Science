#pragma once

#include <initializer_list>

#include "Static_Array.h"

namespace Data_Structures
{
	template<typename Data_Type, const unsigned long long Array_Size>
	struct Node
	{
		Data_Type data {};
		Data_Structures::Static_Array<Node*, Array_Size> links {};

		Node(const Data_Type& data = {}, const std::initializer_list<Node*>& links = {}) : data{data}, links{links}
		{}
	};
}
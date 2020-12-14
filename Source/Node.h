#pragma once

#include <initializer_list>

#include "Static_Array.h"

namespace Data_Structures
{
	template<typename Data_Type, unsigned long long Array_Size>
	struct Node
	{
		Data_Type data {};
		unsigned long long priority {};
		Static_Array<Node*, Array_Size> links {};

		Node(const Data_Type& data = {}, const unsigned long long& priority = {},const std::initializer_list<Node*>& links = {}) : data{data}, priority{priority}, links{links}
		{

		}
	};
}
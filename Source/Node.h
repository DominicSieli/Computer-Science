#pragma once

#include<initializer_list>

#include "Array.h"

namespace Data_Structures
{
	template<typename Data_Type, const unsigned long long Links>
	struct Node
	{
		Data_Type data {};
		Data_Structures::Array<Node*, Links> links {};

		Node(const Data_Type& data = {}, const std::initializer_list<Node*>& links = {}) : data{data}, links{links} {}
	};
}
#pragma once

#include<initializer_list>

#include "Array.h"

namespace DataStructures
{
	template<typename Data_Type, const unsigned long long Links>
	struct Node
	{
		Data_Type data {};
		DataStructures::Array<Node*, Links> links {};

		Node(const Data_Type& data = {}, const std::initializer_list<Node*>& links = {}) : data{data}, links{links} {}
	};
}
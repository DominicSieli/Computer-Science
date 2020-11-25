#pragma once

#include "Array.h"

namespace DataStructures
{
	template<typename Data_Type, const unsigned long long Size>
	struct Node
	{
		Data_Type data {};
		DataStructures::Array<Node*, Size> links {};

		Node(const Data_Type& data = {}) : data{data}
		{

		}
	};
}
#pragma once

namespace DataStructures
{
	template<typename Data_Type, unsigned long long Size>
	struct Node
	{
		Data_Type data {};
		Node* link[Size] {};
	};
}
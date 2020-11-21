#pragma once

namespace DataStructures
{
	template<typename T, unsigned int P>
	struct Node
	{
		T data = {};
		Node* pointers[P] = {};
	};
}
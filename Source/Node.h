#pragma once

namespace DataStructures
{
	template<typename T, unsigned int Size>
	struct Node
	{
		T data = {};
		Node* link[Size] = {};
	};
}
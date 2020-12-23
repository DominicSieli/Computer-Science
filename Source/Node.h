#pragma once

#include <initializer_list>

#include "Static_Array.h"

namespace Data_Structures
{
	template<typename T, unsigned short N>
	struct Node
	{
		T data {};
		Static_Array<Node*, N> links {};

		Node(const T& data = {}, const std::initializer_list<Node*>& links = {}) : data{data}, links{links}
		{}
	};
}
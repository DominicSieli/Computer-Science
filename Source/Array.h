#pragma once

#include<initializer_list>

namespace DataStructures
{
	template<typename Data_Type, unsigned long long Array_Size>
	class Array
	{
	private:
		Data_Type array[Array_Size] {};

	public:
		Array(const std::initializer_list<Data_Type>& data)
		{
			unsigned long long index = 0;

			for(auto x : data)
			{
				array[index] = x;
				index++;
			}
		}

		constexpr unsigned long long Size() const noexcept
		{
			return Array_Size;
		}

		void Clear() noexcept
		{
			for(unsigned long long i = 0; i < Array_Size; i++)
			{
				array[i] = {};
			}
		}

		Data_Type& operator[](const unsigned long long& index)
		{
			return array[index];
		}

		constexpr Data_Type& operator[](const unsigned long long& index) const
		{
			return array[index];
		}
	};
}
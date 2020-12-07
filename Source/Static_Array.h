#pragma once

#include <initializer_list>

namespace Data_Structures
{
	template<typename Data_Type, const unsigned long long Array_Size>
	class Static_Array
	{
	private:
		Data_Type array[Array_Size] {};

	public:
		Static_Array(const std::initializer_list<Data_Type>& data)
		{
			unsigned long long index = 0;

			for(Data_Type item : data)
			{
				array[index++] = item;
			}
		}

		~Static_Array()
		{
			
		}

		constexpr unsigned long long Size() const noexcept
		{
			return Array_Size;
		}

		void Clear() noexcept
		{
			for(unsigned long long index = 0; index < Array_Size; index++)
			{
				array[index] = {};
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
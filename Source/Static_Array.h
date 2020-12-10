#pragma once

#include <initializer_list>

namespace Data_Structures
{
	using Index_Type = unsigned long long;

	template<typename Data_Type, const Index_Type Array_Size>
	class Static_Array
	{
	private:
		Index_Type count = 0;
		Data_Type array[Array_Size] {};

	public:
		Static_Array(const std::initializer_list<Data_Type>& data)
		{
			Index_Type index = 0;

			for(Data_Type item : data)
			{
				array[index++] = item;
			}
		}

		~Static_Array()
		{

		}

		constexpr Index_Type Size() const noexcept
		{
			return Array_Size;
		}

		void Clear() noexcept
		{
			for(Index_Type index = 0; index < Array_Size; index++)
			{
				array[index] = {};
			}
		}

		void Add(const Data_Type& data)
		{
			if(count < Array_Size)
			{
				array[count++] = data;
			}
		}

		void Remove(const Index_Type& index)
		{
			if(count > 0 && index < count)
			{
				count--;
				std::swap(array[index], array[count]);
			}
		}

		Data_Type& operator[](const Index_Type& index)
		{
			return array[index];
		}

		constexpr Data_Type& operator[](const Index_Type& index) const
		{
			return array[index];
		}
	};
}
#pragma once

namespace DataStructures
{
	template<typename Data_Type, unsigned long long Array_Size>
	class Static_Array
	{
	private:
		Data_Type array[Array_Size] {};

	public:
		constexpr unsigned long long Size() const noexcept
		{
			return Array_Size;
		}

		Data_Type& operator[](unsigned long long index)
		{
			return array[index];
		}

		constexpr Data_Type& operator[](unsigned long long index) const
		{
			return array[index];
		}
	};
}
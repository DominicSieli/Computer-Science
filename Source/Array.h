#pragma once

namespace DataStructures
{
	template<typename Data_Type, unsigned long long Array_Size>
	class Array
	{
	private:
		Data_Type array[Array_Size] {};

	public:
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
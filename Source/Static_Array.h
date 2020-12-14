#pragma once

#include <initializer_list>

namespace Data_Structures
{
	template<typename Data_Type, const unsigned long long Array_Size>
	class Static_Array
	{
	private:
		unsigned long long count {};
		Data_Type array[Array_Size] {};

	public:
		Static_Array(const Data_Type& data)
		{
			Fill(data);
		}

		Static_Array(const std::initializer_list<Data_Type>& data = {})
		{
			for(const Data_Type& element : data)
			{
				Add(element);
			}
		}

		~Static_Array()
		{

		}

		constexpr unsigned long long Size() const noexcept
		{
			return Array_Size;
		}

		constexpr unsigned long long Count() const noexcept
		{
			return count;
		}

		void Fill(const Data_Type& value) noexcept
		{
			count = Array_Size;

			for(unsigned long long index = 0; index < Array_Size; index++)
			{
				array[index] = value;
			}
		}

		void Clear() noexcept
		{
			count = 0;

			for(unsigned long long index = 0; index < Array_Size; index++)
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

		void Remove(const unsigned long long& index)
		{
			if(count > 0 && index >= 0 && index < count)
			{
				count--;
				array[index] = {};
				std::swap(array[index], array[count]);
			}
		}

		void Ordered_Remove(const unsigned long long& index)
		{
			if(count > 0 && index >= 0 && index < count)
			{
				count--;
				array[index] = {};

				for(unsigned long long i = index; i < count; i++)
				{
				    std::swap(array[i], array[i + 1]);
				}
			}
		}

		void Remove_Value(const Data_Type& value)
		{
			for(unsigned long long index = 0; index < Array_Size; index++)
			{
				if(array[index] == value)
				{
					Remove(index);
					index--;
				}
			}
		}

		void Ordered_Remove_Value(const Data_Type& value)
		{
			for(unsigned long long index = 0; index < Array_Size; index++)
			{
				if(array[index] == value)
				{
					Ordered_Remove(index);
					index--;
				}
			}
		}

		Data_Type& operator[](const unsigned long long& index)
		{
			if(index < 0)
			{
				return array[0];
			}

			if(index >= Array_Size)
			{
				return array[Array_Size - 1];
			}

			return array[index];
		}

		constexpr Data_Type& operator[](const unsigned long long& index) const
		{
			if(index < 0)
			{
				return array[0];
			}

			if(index >= Array_Size)
			{
				return array[Array_Size - 1];
			}

			return array[index];
		}

		void operator=(const std::initializer_list<Data_Type>& data)
		{
			Clear();

			for(const Data_Type& element : data)
			{
				Add(element);
			}
		}
	};
}
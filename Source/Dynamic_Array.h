#pragma once

#include <initializer_list>

namespace Data_Structures
{
	using Index_Type = unsigned long long;

	template<typename Data_Type, const Index_Type Array_Size = 0>
	class Dynamic_Array
	{
	private:
		Index_Type size = 0;
		Index_Type count = 0;
		Data_Type* array = nullptr;

	public:
		Dynamic_Array(const std::initializer_list<Data_Type>& data = {}) : size{Array_Size}, count{0}, array{new Data_Type[Array_Size]}
		{
			for(Data_Type item : data)
			{
				Add(item);
			}
		}

		Dynamic_Array(const Dynamic_Array& copy_array) : size{copy_array.size}, count{copy_array.count}, array{new Data_Type[copy_array.size]}
		{
			for(Index_Type index = 0; index < copy_array.Size(); index++)
			{
				array[index] = copy_array[index];
			}
		}

		~Dynamic_Array()
		{
			delete[] array;
			array = nullptr;
		}

		Data_Type& operator[](const Index_Type& index)
		{
			return array[index];
		}

		constexpr Data_Type& operator[](const Index_Type& index) const
		{
			return array[index];
		}

		constexpr Index_Type Size() const noexcept
		{
			return size;
		}

		constexpr Index_Type Count() const noexcept
		{
			return count;
		}

		void Trim()
		{
			size = count;

			Data_Type* newArray = new Data_Type[size];

			for(Index_Type index = 0; index < count; index++)
			{
				newArray[index] = array[index];
			}

			delete[] array;
			array = newArray;
		}

		void Add(const Data_Type& data)
		{
			if((count + 1) > size)
			{
				size++;
				Data_Type* newArray = new Data_Type[size];

				for(Index_Type index = 0; index < count; index++)
				{
					newArray[index] = array[index];
				}

				delete[] array;
				array = newArray;
			}

			array[count++] = data;
		}

		void Remove(const Index_Type& index)
		{
			if(count > 0 && index < count)
			{
				count--;
				std::swap(array[index], array[count]);
			}
		}
	};
}
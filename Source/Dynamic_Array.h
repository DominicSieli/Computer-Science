#pragma once

#include <initializer_list>

namespace Data_Structures
{
	template<typename Data_Type, const unsigned long long Array_Size = 0>
	class Dynamic_Array
	{
	private:
		Data_Type* array = nullptr;
		unsigned long long size = 0;
		unsigned long long count = 0;

	public:
		Dynamic_Array(const std::initializer_list<Data_Type>& data = {})
			: array{new Data_Type[Array_Size]}, size{Array_Size}, count{0}
		{
			for(Data_Type item : data)
			{
				Add(item);
			}
		}

		Dynamic_Array(const Dynamic_Array& copyArray)
			: array{new Data_Type[copyArray.size]}, size{copyArray.size}, count{copyArray.count}
		{
			for(unsigned long long index = 0; index < copyArray.Size(); index++)
			{
				array[index] = copyArray[index];
			}
		}

		~Dynamic_Array()
		{
			delete[] array;
			array = nullptr;
		}

		Data_Type& operator[](const unsigned long long& index)
		{
			return array[index];
		}

		constexpr Data_Type& operator[](const unsigned long long& index) const
		{
			return array[index];
		}

		constexpr unsigned long long Size() const noexcept
		{
			return size;
		}

		constexpr unsigned long long Count() const noexcept
		{
			return count;
		}

		void Trim()
		{
			size = count;

			Data_Type* newArray = new Data_Type[size];

			for(unsigned long long index = 0; index < count; index++)
			{
				newArray[index] = array[index];
			}

			delete[] array;
			array = newArray;
		}

		void Add(const Data_Type& data)
		{
			count++;

			if(count > size)
			{
				size++;
				Data_Type* newArray = new Data_Type[size];

				for(unsigned long long index = 0; index < count - 1; index++)
				{
					newArray[index] = array[index];
				}

				delete[] array;
				array = newArray;
			}

			array[count - 1] = data;
		}

		void Remove(const unsigned long long& index)
		{
			if(count > 0 && index < count)
			{
				count--;
				Data_Type temp1 = array[index];
				Data_Type temp2 = array[count];

				array[index] = temp2;
				array[count] = temp1;
			}
		}
	};
}
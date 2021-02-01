#pragma once

#include <initializer_list>

namespace Data_Structures
{
	template<typename T, const unsigned long long S>
	class Vector
	{
	private:
	    T* vector = nullptr;
		unsigned long long size = 0;
		unsigned long long count = 0;

	public:
		Vector(const std::initializer_list<T>& list = {}) : size{S}, count{0}, vector{new T[S]}
		{
			for(T data : list)
			{
				Add(data);
			}
		}

		Vector(const Vector& copy_vector) : size{copy_vector.size}, count{copy_vector.count}, vector{new T[copy_vector.size]}
		{
			for(unsigned long long index = 0; index < copy_vector.Size(); index++)
			{
				vector[index] = copy_vector[index];
			}
		}

		~Vector()
		{
			delete[] vector;
			vector = nullptr;
		}

		T& operator[](const unsigned long long& index) noexcept
		{
			return vector[index];
		}

		constexpr T& operator[](const unsigned long long& index) const noexcept
		{
			return vector[index];
		}

		constexpr unsigned long long Size() const noexcept
		{
			return size;
		}

		constexpr unsigned long long Count() const noexcept
		{
			return count;
		}

		void Trim() noexcept
		{
			size = count;

			T* newArray = new T[size];

			for(unsigned long long index = 0; index < count; index++)
			{
				newArray[index] = vector[index];
			}

			delete[] vector;
			vector = newArray;
		}

		void Add(const T& data) noexcept
		{
			if((count + 1) > size)
			{
				size++;
				T* newArray = new T[size];

				for(unsigned long long index = 0; index < count; index++)
				{
					newArray[index] = vector[index];
				}

				delete[] vector;
				vector = newArray;
			}

			vector[count++] = data;
		}

		void Remove(const unsigned long long& index) noexcept
		{
			if(count > 0 && index < count)
			{
				count--;
				std::swap(vector[index], vector[count]);
			}
		}

		void Reverse() noexcept
		{
			for(unsigned long long i = 0; i < count / 2; i++)
			{
				std::swap(vector[i], vector[(count - 1) - i]);
			}
		}
	};
}
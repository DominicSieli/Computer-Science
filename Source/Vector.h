#pragma once

#include <initializer_list>

namespace Data_Structures
{
	template<typename T>
	class Vector
	{
	private:
	    T* vector = nullptr;
		unsigned long long size = 0;
		unsigned long long count = 0;

	public:
		Vector()
		{}

		Vector(const unsigned long long& size) : vector{new T[size]}, size{size}, count{0}
		{}

		Vector(const T& data, const unsigned long long& size) : vector{new T[size]}, size{size}, count{size}
		{
			Fill(data);
		}

		Vector(const std::initializer_list<T>& list)
		{
			for(const T& data : list)
			{
				Add(data);
			}
		}

		Vector(const Vector& copy_vector) : vector{new T[copy_vector.size]}, size{copy_vector.size}, count{copy_vector.count}
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

		constexpr unsigned long long Size() const noexcept
		{
			return size;
		}

		constexpr unsigned long long Count() const noexcept
		{
			return count;
		}

		void Fill(const T& data) noexcept
		{
			count = size;

			for(unsigned long long index = 0; index < size; index++)
			{
				vector[index] = data;
			}
		}

		void Clear() noexcept
		{
			count = 0;

			for(unsigned long long index = 0; index < size; index++)
			{
				vector[index] = {};
			}
		}

		void Delete() noexcept
		{
			size = 0;
			count = 0;
			delete[] vector;
			vector = nullptr;
		}

		void Trim() noexcept
		{
			size = count;

			T* new_vector = new T[size];

			for(unsigned long long index = 0; index < count; index++)
			{
				new_vector[index] = vector[index];
			}

			delete[] vector;
			vector = new_vector;
		}

		void Add(const T& data, const unsigned long long expansion = size) noexcept
		{
			count++;

			if(count > size)
			{
				size += expansion;
				T* new_vector = new T[size];

				for(unsigned long long index = 0; index < count; index++)
				{
					new_vector[index] = vector[index];
				}

				delete[] vector;
				vector = new_vector;
			}

			vector[count - 1] = data;
		}

		void Sorted_Add(const T& data, const unsigned long long expansion = size) noexcept
		{
			count++;

			if(count > size)
			{
				size += expansion;
				T* new_vector = new T[size];

				for(unsigned long long index = 0; index < count; index++)
				{
					new_vector[index] = vector[index];
				}

				delete[] vector;
				vector = new_vector;
			}

			vector[count - 1] = data;

			for(unsigned long long i = count - 1; i > 0; i--)
			{
				if(vector[i] < vector[i - 1])
				{
					std::swap(vector[i], vector[i - 1]);
				}
			}
		}

		void Remove(const unsigned long long& index) noexcept
		{
			if(count == 0)
			{
				return;
			}

			if(index >= 0 && index < count)
			{
				count--;
				vector[index] = {};
				std::swap(vector[index], vector[count]);
			}
		}

		void Sorted_Remove(const unsigned long long& index) noexcept
		{
			if(count == 0)
			{
				return;
			}

			if(index >= 0 && index < count)
			{
				count--;
				vector[index] = {};

				for(unsigned long long i = index; i < count; i++)
				{
				    std::swap(vector[i], vector[i + 1]);
				}
			}
		}

		void Reverse() noexcept
		{
			for(unsigned long long i = 0; i < count / 2; i++)
			{
				std::swap(vector[i], vector[(count - 1) - i]);
			}
		}

		T& operator[](const unsigned long long& index) noexcept
		{
			if(index < 0)
			{
				return vector[0];
			}

			if(index >= count)
			{
				return vector[count - 1];
			}

			return vector[index];
		}

		constexpr T& operator[](const unsigned long long& index) const noexcept
		{
			if(index < 0)
			{
				return vector[0];
			}

			if(index >= count)
			{
				return vector[count - 1];
			}

			return vector[index];
		}

		void operator=(const std::initializer_list<T>& list) noexcept
		{
			Delete();

			for(const T& data : list)
			{
				Add(data, 1);
			}
		}

		void Sort()
		{
			bool sorted = false;
			unsigned long long j = 0;
			unsigned long long l = 0;
			unsigned long long r = count - 1;

			while(sorted == false)
			{
				sorted = true;

				for(unsigned int i = l; i < r; i++)
				{
					j = (count - i) - 1;

					if(i < j && vector[i] > vector[j])
					{
						sorted = false;
						std::swap(vector[i], vector[j]);
					}

					if(vector[i] > vector[i + 1])
					{
						sorted = false;
						std::swap(vector[i], vector[i + 1]);
					}

					if(vector[j] < vector[j - 1])
					{
						sorted = false;
						std::swap(vector[j], vector[j - 1]);
					}
				}

				l++;
				r--;
			}
		}
	};
}
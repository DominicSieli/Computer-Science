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
		Vector(const unsigned long long& initial_size = 0, const T& data = {})
		{
			if(initial_size > 0)
			{
				size = initial_size;
				vector = new T[initial_size];
				Fill(data);
			}
		}

		Vector(const std::initializer_list<T>& list) : vector{new T[list.size()]}, size{list.size()}, count{0}
		{
			for(const T& data : list)
			{
				Add(data);
			}
		}

		Vector(const Vector& copy_vector) : vector{new T[copy_vector.size]}, size{copy_vector.size}, count{copy_vector.count}
		{
			for(unsigned long long index = 0; index < size; index++)
			{
				vector[index] = copy_vector[index];
			}
		}

		~Vector()
		{
			delete[] vector;
			vector = nullptr;
		}

		T& operator[](const unsigned long long& index) const
		{
			return vector[index];
		}

		constexpr T& operator[](const unsigned long long& index)
		{
			return vector[index];
		}

		void operator=(const std::initializer_list<T>& list)
		{
			Delete();

			for(const T& data : list)
			{
				Add(data);
			}
		}

		constexpr unsigned long long Size() const noexcept
		{
			return size;
		}

		constexpr unsigned long long Count() const noexcept
		{
			return count;
		}

		void Fill(const T& data)
		{
			count = size;

			for(unsigned long long index = 0; index < size; index++)
			{
				vector[index] = data;
			}
		}

		void Clear()
		{
			count = 0;

			for(unsigned long long index = 0; index < size; index++)
			{
				vector[index] = {};
			}
		}

		void Delete()
		{
			size = 0;
			count = 0;
			delete[] vector;
			vector = nullptr;
		}

		void Trim()
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

		void Add(const T& data, const unsigned long long& expansion = 1, const bool& sort = false)
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

			if(sort == true)
			{
				Sort();
			}
		}

		void Remove(const unsigned long long& index, const bool& sort = false)
		{
			if(index >= 0 && index < count)
			{
				count--;
				vector[index] = {};
				std::swap(vector[index], vector[count]);
			}

			if(sort == true)
			{
				Sort();
			}
		}

		void Reverse()
		{
			for(unsigned long long index = 0; index < count / 2; index++)
			{
				std::swap(vector[index], vector[(count - 1) - index]);
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
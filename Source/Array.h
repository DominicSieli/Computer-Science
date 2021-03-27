#pragma once

#include <initializer_list>

namespace Data_Structures
{
	template<typename T, unsigned long long S>
	class Array
	{
	private:
		T array[S] {};
		unsigned long long count = 0;

	public:
		Array()
		{}

		Array(const T& data)
		{
			Fill(data);
		}

		Array(const std::initializer_list<T>& list)
		{
			for(const T& data : list)
			{
				Add(data);
			}
		}

		~Array()
		{}

		T& operator[](const unsigned long long& index) const
		{
			return array[index];
		}

		constexpr T& operator[](const unsigned long long& index)
		{
			return array[index];
		}

		void operator=(const std::initializer_list<T>& list)
		{
			Clear();

			for(const T& data : list)
			{
				Add(data);
			}
		}

		constexpr unsigned long long Size() const noexcept
		{
			return S;
		}

		constexpr unsigned long long Count() const noexcept
		{
			return count;
		}

		void Fill(const T& data)
		{
			count = S;

			for(unsigned long long index = 0; index < S; index++)
			{
				array[index] = data;
			}
		}

		void Clear()
		{
			count = 0;

			for(unsigned long long index = 0; index < S; index++)
			{
				array[index] = {};
			}
		}

		void Add(const T& data, const bool& sort = false)
		{
			if(count < S)
			{
				count++;
				array[count - 1] = data;
			}

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
				array[index] = {};
				std::swap(array[index], array[count]);
			}

			if(sort == true)
			{
				Sort();
			}
		}

		void Reverse()
		{
			for(unsigned long long i = 0; i < count / 2; i++)
			{
				std::swap(array[i], array[(count - 1) - i]);
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

					if(i < j && array[i] > array[j])
					{
						sorted = false;
						std::swap(array[i], array[j]);
					}

					if(array[i] > array[i + 1])
					{
						sorted = false;
						std::swap(array[i], array[i + 1]);
					}

					if(array[j] < array[j - 1])
					{
						sorted = false;
						std::swap(array[j], array[j - 1]);
					}
				}

				l++;
				r--;
			}
		}
	};
}
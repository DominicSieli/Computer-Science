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

		constexpr unsigned long long Size() const noexcept
		{
			return S;
		}

		constexpr unsigned long long Count() const noexcept
		{
			return count;
		}

		void Fill(const T& data) noexcept
		{
			count = S;

			for(unsigned long long index = 0; index < S; index++)
			{
				array[index] = data;
			}
		}

		void Clear() noexcept
		{
			count = 0;

			for(unsigned long long index = 0; index < S; index++)
			{
				array[index] = {};
			}
		}

		void Add(const T& data) noexcept
		{
			if(count < S)
			{
				count++;
				array[count - 1] = data;
			}
		}

		void Sorted_Add(const T& data) noexcept
		{
			if(count < S)
			{
				count++;
				array[count - 1] = data;
			}

			for(unsigned long long i = count - 1; i > 0; i--)
			{
				if(array[i] < array[i - 1])
				{
					std::swap(array[i], array[i - 1]);
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
				array[index] = {};
				std::swap(array[index], array[count]);
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
				array[index] = {};

				for(unsigned long long i = index; i < count; i++)
				{
				    std::swap(array[i], array[i + 1]);
				}
			}
		}

		void Reverse() noexcept
		{
			for(unsigned long long i = 0; i < count / 2; i++)
			{
				std::swap(array[i], array[(count - 1) - i]);
			}
		}

		T& operator[](const unsigned long long& index) noexcept
		{
			if(index < 0)
			{
				return array[0];
			}

			if(index >= count)
			{
				return array[count - 1];
			}

			return array[index];
		}

		constexpr T& operator[](const unsigned long long& index) const noexcept
		{
			if(index < 0)
			{
				return array[0];
			}

			if(index >= count)
			{
				return array[count - 1];
			}

			return array[index];
		}

		void operator=(const std::initializer_list<T>& list) noexcept
		{
			Clear();

			for(const T& data : list)
			{
				if(count < S)
				{
					Add(data);
				}
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
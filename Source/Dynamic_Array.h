#pragma once

namespace DataStructures
{
	template <typename T>
	class DynamicArray
	{
	private:
		T *array = nullptr;
		unsigned int size = 0;
		unsigned int count = 0;

	public:
		DynamicArray(unsigned int size)
			: array(new T[size]), size(size), count(0)
		{

		}

		~DynamicArray()
		{
			delete[] array;
		}

		T& operator[](unsigned int index)
		{
			return array[index];
		}

		unsigned int Count() const
		{
			return count;
		}

		void Add(T value)
		{
			if (count < size)
			{
				count++;
				array[count - 1] = value;
			}
		}

		void Remove(unsigned int index)
		{
			if (index < count && count > 0)
			{
				count--;
				T temp1 = array[index];
				T temp2 = array[count];

				array[index] = temp2;
				array[count] = temp1;
			}
		}
	};
}
#pragma once

template <typename T>
class Vector
{
private:
	T *vector = nullptr;
	unsigned int size = 0;
	unsigned int count = 0;

public:
	Vector(unsigned int size) : vector{new T[size]},
								size{size},
								count{0}
	{
	}

	T &operator[](unsigned int index)
	{
		return vector[index];
	}

	unsigned int Count() const
	{
		return count;
	}

	~Vector()
	{
		delete[] vector;
	}

	void Add(T value)
	{
		if (count < size)
		{
			count++;
			vector[count - 1] = value;
		}
	}

	void Remove(unsigned int index)
	{
		if (index < count && count > 0)
		{
			count--;
			T temp1 = vector[index];
			T temp2 = vector[count];

			vector[index] = temp2;
			vector[count] = temp1;
		}
	}
};
#pragma once

namespace Math
{
	template <typename T>
	inline T Power(T base, T exponent)
	{
		T power = 1;

		for (unsigned int i = 0; i < exponent; i++)
		{
			power *= base;
		}

		return power;
	}

	template <typename T>
	inline T Factorial(T number)
	{
		T factorial = number;

		for (unsigned int i = number; i > 1; i--)
		{
			factorial += factorial * (number - i);
		}

		return factorial;
	}

	template <typename T>
	inline T Logarithm(T base, T power)
	{
		T exponent = 0;

		while (Power(base, exponent) < power)
		{
			exponent++;
		}

		return exponent;
	}

	inline unsigned int Summation(unsigned int indexStart, unsigned int indexStop, int exponent = 1)
	{
		unsigned int sum = 0;

		for (unsigned int index = indexStart; index < indexStop + 1; index++)
		{
			sum += Power<unsigned int>(index, exponent);
		}

		return sum;
	}
} // namespace Math
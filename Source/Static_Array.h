#pragma once

namespace DataStructures
{
	template <typename T, unsigned long long S>
	class StaticArray
	{
	private:
		T array[S];

	public:
		constexpr unsigned long long Size() const noexcept
		{
			return S;
		}

		T& operator[](unsigned long long index)
		{
			return array[index];
		}

		constexpr T& operator[](unsigned long long index) const
		{
			return array[index];
		}
	};
}
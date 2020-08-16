#pragma once

namespace DataStructures
{
	template <typename T, unsigned long long S>
	class Array
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

		const T& operator[](unsigned long long index) const
		{
			return array[index];
		}

		T* Data() noexcept
		{
			return array;
		}

		const T* Data() const noexcept
		{
			return array;
		}
	};
}
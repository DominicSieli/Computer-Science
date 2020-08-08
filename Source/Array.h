#pragma once

template <typename T, unsigned long long S>
class Array
{
private:
	T data[S];

public:
	constexpr unsigned long long Size() const { return S; }

	T& operator[](unsigned long long index) { return data[index]; }
	const T& operator[](unsigned long long index) const { return data[index]; }

	T* Data() { return data; }
	const T* Data() const { return data; }
};
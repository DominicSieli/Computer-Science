#pragma once

namespace DataStructures
{
	template<typename T>
	struct ArrayNode
	{
	private:
		T* arrayPointer = nullptr;

	public:
		ArrayNode(const unsigned int& size) :
			arrayPointer{ new T[size] }
		{

		}

		~ArrayNode()
		{
			delete[] this->arrayPointer;
		}

		T* ArrayPointer() const
		{
			return this->arrayPointer;
		}

		T& operator[](const unsigned int& index) const
		{
			return this->arrayPointer[index];
		}
	};
}
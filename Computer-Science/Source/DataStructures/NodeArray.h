#pragma once

namespace DataStructures
{
	template<typename T>
	struct NodeArray
	{
	private:
		T** nodes = nullptr;
		unsigned int nodeSize = 0;
		unsigned int totalSize = 0;
		unsigned int nodeSegments = 0;

	public:
		NodeArray(const unsigned int& nodeSize, const unsigned int& nodeSegments) :
			nodes{ new T[nodeSegments] }
		{
			this->nodeSize = nodeSize;
			this->nodeSegments = nodeSegments;
		}

		~NodeArray()
		{
			for(unsigned int i = 0; i < this->nodeSegments; i++)
			{
				delete[] this->nodeSegments[i];
			}
		}
		
		unsigned int Size() const
		{
			return this->totalSize;
		}

		T operator[](const unsigned int& index)
		{
			return this->nodes[index];
		}
	};
}
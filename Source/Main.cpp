#include <iostream>

#include "Dynamic_Array.h"

Data_Structures::Dynamic_Array<int> array({1,2,3,4});
Data_Structures::Dynamic_Array<int> dArray(array);

int main()
{
	std::cout << "Count: " << dArray.Count() << '\n';
	std::cout << "Size: " << dArray.Size() << '\n';

	std::cout << "Count: ";
	for(unsigned long long i = 0; i < dArray.Count(); i++)
	{
		std::cout << dArray[i] << " ";
	}

	std::cout << '\n';

	std::cout << "Size: ";
	for(unsigned long long i = 0; i < dArray.Size(); i++)
	{
		std::cout << dArray[i] << " ";
	}

	std::cout << '\n' << '\n';

	dArray.Add(dArray.Count() + 1);
	std::cout << "Count: " << dArray.Count() << '\n';
	std::cout << "Size: " << dArray.Size() << '\n';

	std::cout << "Count: ";
	for(unsigned long long i = 0; i < dArray.Count(); i++)
	{
		std::cout << dArray[i] << " ";
	}

	std::cout << '\n';

	std::cout << "Size: ";
	for(unsigned long long i = 0; i < dArray.Size(); i++)
	{
		std::cout << dArray[i] << " ";
	}

	std::cout << '\n' << '\n';

	dArray.Remove(dArray.Count() - 1);
	std::cout << "Count: " << dArray.Count() << '\n';
	std::cout << "Size: " << dArray.Size() << '\n';

	std::cout << "Count: ";
	for(unsigned long long i = 0; i < dArray.Count(); i++)
	{
		std::cout << dArray[i] << " ";
	}

	std::cout << '\n';

	std::cout << "Size: ";
	for(unsigned long long i = 0; i < dArray.Size(); i++)
	{
		std::cout << dArray[i] << " ";
	}

	std::cout << '\n' << '\n';

	dArray.Trim();
	std::cout << "Count: " << dArray.Count() << '\n';
	std::cout << "Size: " << dArray.Size() << '\n';

	std::cout << "Count: ";
	for(unsigned long long i = 0; i < dArray.Count(); i++)
	{
		std::cout << dArray[i] << " ";
	}

	std::cout << '\n';

	std::cout << "Size: ";
	for(unsigned long long i = 0; i < dArray.Size(); i++)
	{
		std::cout << dArray[i] << " ";
	}

	std::cout << '\n';

	std::cin.get();
}
#include <string>
#include <iomanip>
#include <iostream>

#include "Hash_Table.h"

Data_Structures::Hash_Table<10, int>* hash_table = new Data_Structures::Hash_Table<10, int>();

int value = 2048;
std::string key = "Dom";

int main()
{
	std::cout << "Table is empty: " << std::boolalpha << hash_table->Empty() << '\n';

	hash_table->Insert(key, value);

	std::cout << hash_table->Search(key) << '\n';

	hash_table->Remove(key);

	std::cout << hash_table->Search(key) << '\n';

	std::cout << "Table is empty: " << std::boolalpha << hash_table->Empty() << '\n';

	std::cin.get();
}
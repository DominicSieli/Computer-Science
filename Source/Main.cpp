#include <string>
#include <iomanip>
#include <iostream>

#include "Hash_Table.h"

Data_Structures::Hash_Table<10, int, std::string>* hash_table = new Data_Structures::Hash_Table<10, int, std::string>();

int main()
{
	std::cout << "Table is empty: " << std::boolalpha << hash_table->Empty() << '\n';

	hash_table->Insert(1, "Dominic");

	std::cout << hash_table->Search(1) << '\n';

	hash_table->Remove(1);

	std::cout << hash_table->Search(1) << '\n';

	std::cout << "Table is empty: " << std::boolalpha << hash_table->Empty() << '\n';
	std::cin.get();
}
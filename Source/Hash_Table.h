#pragma once

#include <list>
#include <string>

namespace Data_Structures
{
    template<unsigned int S, typename V>
    class Hash_Table
    {
    private:
        std::list<std::pair<std::string, V>> table[S];

        unsigned int Hash_Function(std::string key)
        {
            unsigned int hash_key = 0;

            for(const char& chr : key)
            {
                hash_key += (unsigned int)chr;
            }

            return hash_key % S;
        }

    public:
        void Insert(std::string key, V value)
        {
            bool key_found = false;
            unsigned int hash_key = Hash_Function(key);

            for(auto& key_value : table[hash_key])
            {
                if(key_value.first == key)
                {
                    key_found = true;
                    key_value.second = value;
                }
            }

            if(key_found == false)
            {
                table[hash_key].emplace_back(key, value);
            }
        }

        V Search(std::string key)
        {
            unsigned int hash_key = Hash_Function(key);

            for(auto& key_value : table[hash_key])
            {
                if(key_value.first == key)
                {
                    return key_value.second;
                }
            }

            return {};
        }

        void Remove(std::string key)
        {
            unsigned int hash_key = Hash_Function(key);
            auto& cell = table[hash_key];

            for(auto i = cell.begin(); i != cell.end(); ++i)
            {
                if(i->first == key)
                {
                    cell.erase(i);
                    break;
                }
            }
        }

        bool Empty()
        {
            unsigned int total = 0;

            for(unsigned int i = 0; i < S; ++i)
            {
                total += (unsigned int)table[i].size();
            }

            return !total;
        }
    };
}
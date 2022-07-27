#include "HashTable.h"

HashTable::HashTable(size_t size)
{
    table = new list<KeyAndValue>[size];
    _size = size;
}

HashTable::~HashTable()
{
    delete[] table;
}

size_t HashTable::hashing(const string& name) const
{
    size_t index = name[0] - 'A' + name[1] - 'a';
    return index % _size;
}

void HashTable::add(const string& name, long number)
{
    size_t index = hashing(name);
    for (KeyAndValue kv : table[index])
    {
        if (name == kv.name)
            throw out_of_range(name + " already exist and has " + to_string(number));
    }
    table[index].push_back({number, name});
}

long HashTable::number(const string& name) const
{
    size_t index = hashing(name);
    for (KeyAndValue kv : table[index])
    {
        if (name == kv.name)
            return kv.number;
    }
    throw out_of_range("The Name " + name + " does not exist");
}

bool HashTable::remove(const string& name)
{
    size_t index = hashing(name);
    for (list<KeyAndValue>::iterator it = table[index].begin(); it != table[index].end(); it++)
    {
        if (name == it->name)
        {
            table[index].erase(it);
            return true;
        }
    }
    return false;
}

size_t HashTable::size() const
{
    return _size;
}

float HashTable::loadFactor() const
{
    size_t occupied = 0;
    for (size_t i = 0; i < _size; i++)
    {
        if (table[i].size() > 0)
            occupied++;
    }
    return ((static_cast<float>(occupied)) / _size) * 100;
}

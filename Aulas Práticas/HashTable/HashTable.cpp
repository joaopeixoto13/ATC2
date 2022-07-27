#include "HashTable.h"

HashTable::HashTable(size_t size)
{
	table = new list<Student>[size];
	_size = size;
}

HashTable::~HashTable()
{
	delete[] table;
}

size_t HashTable::hashing(int number) const
{
	return (number % _size);
}

void HashTable::add(Student& student)
{
	size_t index = hashing(student.number);
	table[index].push_back(student);
}

string HashTable::name(int number) const
{
	size_t index = hashing(number);
	for (Student st : table[index])
	{
		if (st.number == number)
			return st.name;
	}
	throw out_of_range("The number does not exist!");
}

bool HashTable::remove(int number)
{
	size_t index = hashing(number);
	for (list<Student>::iterator it = table[index].begin(); it != table[index].end(); it++)
	{
		if (it->number == number)
		{
			table[index].erase(it);
			return true;
		}
	}
	return false;
}

size_t HashTable::size() const
{
	size_t count = 0;
	for (size_t i = 0; i < _size; i++)
		count += table[i].size();
	return count;
}

float HashTable::loadFactor() const
{
	size_t occupied = 0;
	for (size_t i = 0; i < _size; i++)
	{
		if (table[i].size() > 0)
			occupied++;
	}
	return (static_cast<float>(occupied) / _size) * 100;
}

void HashTable::dump() const
{
	for (size_t i = 0; i < _size; i++)
		cout << "Table[" << to_string(i) << "] size = " << table[i].size() << endl;
}

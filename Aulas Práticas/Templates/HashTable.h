#pragma once
#include <list>
#include <string>
#include <iostream>

using namespace std;

struct Student
{
	int number;
	string name;

	size_t operator%(size_t a)
	{
		return this->number % a;
	}

	bool operator==(const Student& st)
	{
		if (this->name == st.name && this->number == st.number)
			return true;
		return false;
	}

	friend ostream& operator<<(ostream& oss, const Student& st)
	{
		oss << st.name << " " << st.number;
		return oss;
	}
};

//
//size_t operator%(string a, size_t x)
//{
//	return a[0] - 'A' + a[1] - 'a';
//}

template<typename T>
class HashTable
{
	size_t _size;
	list<T>* table;
	size_t hashing(T x) const {
		return x % _size;
	}

public:
	HashTable(size_t _size) : _size(_size)
	{
		table = new list<T>[_size];
	}
	~HashTable()
	{
		delete[] table;
	}
	void add(const T& x)
	{
		size_t index = hashing(x);
		table[index].push_back(x);
	}
	bool contains(const T& x)
	{
		size_t index = hashing(x);
		for (T i : table[index])
		{
			if (i == x)
				return true;
		}
		return false;
	}
	bool remove(const T& x)
	{
		size_t index = hashing(x);
		for (typename list<T>::iterator it = table[index].begin(); it != table[index].end(); it++)
		{
			if (*it == x)
			{
				table[index].erase(it);
				return true;
			}
		}
		return false;
	}

	void print()
	{
		for (size_t i = 0; i < _size; i++)
		{
			for (T j : table[i])
				cout << j << endl;
		}
	}

};

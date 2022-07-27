#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct KeyAndValue
{
	long number;
	string name;
};

class HashTable
{
	list<KeyAndValue>* table;
	size_t _size;
	size_t hashing(const string& name) const;

public:
	HashTable(size_t size);
	~HashTable();

	void add(const string& name, long number);
	long number(const string& name) const;
	bool remove(const string& name);
	size_t size() const;
	float loadFactor() const;

};


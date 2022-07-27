#pragma once
#include <string>
#include <iostream>
#include <list>

using namespace std;

struct Student
{
	int number;
	string name;
};

class HashTable
{
	list<Student>* table;
	size_t _size;
	size_t hashing(int number) const;

public:
	HashTable(size_t size);
	~HashTable();

	void add(Student& student);
	string name(int number) const;
	bool remove(int number);
	size_t size() const;
	float loadFactor() const;
	void dump() const;
};


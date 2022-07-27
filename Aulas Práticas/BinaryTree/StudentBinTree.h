#pragma once
#include "StudentNode.h"

class StudentBinTree
{
	StudentNode* root;
	size_t _size;
	size_t _height;

public:
	StudentBinTree();
	void add(const Student& a);
	bool cointains(int number);
	bool contains(string name);
	//bool remove(int number);
	size_t size();
	size_t height();
	vector<Student> inOrder();
	vector<Student> preOreder();
	vector<Student> posOreder();
	vector<Student> levelOrder();
};


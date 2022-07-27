#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Student
{
	int number;
	string name;
};

class StudentNode
{
	StudentNode* left;
	StudentNode* right;
	Student a;

public:
	StudentNode(const Student& a);
	size_t add(StudentNode* n);
	bool contains(int number);
	bool contains(string name);
	//StudentNode* remove(StudentNode* root, StudentNode* n);
	void inOrder(vector<Student>& elements);
	void preOrder(vector<Student>& elements);
	void posOrder(vector<Student>& elements);
	void levelOrder(vector<Student>& elements, StudentNode* root);
};


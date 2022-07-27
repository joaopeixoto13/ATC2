#include "StudentNode.h"
#include <stdexcept>
#include <queue>

StudentNode::StudentNode(const Student& a)
	: left(nullptr) , right(nullptr), a(a)
{}


size_t StudentNode::add(StudentNode* n)			// ordem alfabetica
{
	if (n->a.name.compare(a.name) < 0)
	{
		if (left)
			return left->add(n) + 1;
		else
		{
			left = n;
			return 1;
		}
	}
	else if (n->a.name.compare(a.name) > 0)
	{
		if (right)
			return right->add(n) + 1;
		else
		{
			right = n;
			return 1;
		}
	}
	else
	{
		if (n->a.number < a.number)
		{
			left = n;
			return 1;
		}
		else if (n->a.number > a.number)
		{
			right = n;
			return 1;
		}
		else
			throw invalid_argument("Student already exist ... ");
	}
}


bool StudentNode::contains(int number)
{
	if (number < a.number)
	{
		if (left)
			left->contains(number);
		else
			return false;
	}
	else if (number > a.number)
	{
		if (right)
			right->contains(number);
		else
			return false;
	}
	else
		return true;
}


bool StudentNode::contains(string name)
{
	if (name.compare(a.name) < 0)
	{
		if (left)
			return left->contains(name);
		else
			return false;
	}
	else if (name.compare(a.name) > 0)
	{
		if (right)
			return right->contains(name);
		else
			return false;
	}
	else
		return true;
}




//StudentNode* StudentNode::remove(StudentNode* root, StudentNode* n)
//{
//
//}

void StudentNode::inOrder(vector<Student>& elements)
{
	if (left)
		left->inOrder(elements);
	elements.push_back(a);
	if (right)
		right->inOrder(elements);
}

void StudentNode::preOrder(vector<Student>& elements)
{
	elements.push_back(a);
	if (left)
		left->preOrder(elements);
	if (right)
		right->preOrder(elements);
}

void StudentNode::posOrder(vector<Student>& elements)
{
	if (left)
		left->posOrder(elements);
	if (right)
		right->posOrder(elements);
	elements.push_back(a);
}

void StudentNode::levelOrder(vector<Student>& elements, StudentNode* root)
{
	queue<StudentNode*> fila;
	fila.push(root);
	while (!fila.empty()) {
		StudentNode* atual = fila.front();
		fila.pop();
		elements.push_back(atual->a);
		if (atual->left)
			fila.push(atual->left);
		if (atual->right)
			fila.push(atual->right);
	}
}

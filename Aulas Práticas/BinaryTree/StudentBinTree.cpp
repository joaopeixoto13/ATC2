#include "StudentBinTree.h"

StudentBinTree::StudentBinTree()
	: root(nullptr) , _size(0) , _height(0)
{ }

void StudentBinTree::add(const Student& a)
{
	StudentNode* n = new StudentNode(a);
	if (!root)
		root = n;
	else
	{
		if (root->add(n) < _height)
			_height++;
	}
}


bool StudentBinTree::cointains(int number)
{
	if (!root)
		return false;
	else
		return root->contains(number);
}

bool StudentBinTree::contains(string name)
{
	if (!root)
		return false;
	return root->contains(name);
}


size_t StudentBinTree::size()
{
	return _size;
}

size_t StudentBinTree::height()
{
	return _height;
}

vector<Student> StudentBinTree::inOrder()
{
	vector<Student>elements;
	if (root)
		root->inOrder(elements);
	return elements;
}

vector<Student> StudentBinTree::preOreder()
{
	vector<Student>elements;
	if (root)
		root->preOrder(elements);
	return elements;
}

vector<Student> StudentBinTree::posOreder()
{
	vector<Student>elements;
	if (root)
		root->posOrder(elements);
	return elements;
}

vector<Student> StudentBinTree::levelOrder()
{
	vector<Student>elements;
	if (root)
		root->levelOrder(elements, root);
	return elements;
}

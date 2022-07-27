#pragma once
#include <vector>

template<typename T>
class BinTreeNode
{
	T value;
	BinTreeNode* left;
	BinTreeNode* right;

public:
	BinTreeNode(T value) : value(value), left(nullptr), right(nullptr) {}
	size_t add(BinTreeNode* n)
	{
		if (n->value < value)
		{
			if (left)
				return left->add(n) + 1;
			else
			{
				left = n;
				return 1;
			}
		}
		else if (n->value > value)
		{
			if (right)
				return right->add(n) + 1;
			else
			{
				right = n;
				return 1;
			}
		}
	}
	bool contains(T value) 
	{
		if (value < this->value)
		{
			if (left)
				return left->contains(value);
			else
				return false;
		}
		else if (value > this->value)
		{
			if (right)
				return right->contains(value);
			else
				return false;
		}
		else
			return true;
	}

	void inOrder(vector<T>& elements)
	{
		if (left)
			left->inOrder(elements);
		elements.push_back(value);
		if (right)
			right->inOrder(elements);
	}
};


template <typename T>
class BinTree
{
	BinTreeNode<T>* tree;
	size_t _size;
	size_t _height;

public:
	BinTree() : tree(nullptr), _size(0), _height(0) {}
	void add(T value)
	{
		BinTreeNode<T>* n = new BinTreeNode<T>(value);
		if (!tree)
			tree = n;
		else
		{
			if (tree->add(n) > _height)
				_height++;
		}
	}
	bool contains(T value)
	{
		if (!tree)
			return false;
		return tree->contains(value);
	}

	vector<T> inOrder()
	{
		vector<T> elements;
		if (tree)
			tree->inOrder(elements);
		return elements;
	}

	size_t size() const
	{
		return _size;
	}

	size_t height() const
	{
		return _height;
	}

};

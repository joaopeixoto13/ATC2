#pragma once
#include <iostream>

using namespace std;

template <typename T>
class List;

template<typename T>
class ListNode
{
	friend List<T>;
	T value;
	ListNode* next;

public:
	ListNode() : value(0), next(nullptr) {}
	ListNode(T value, ListNode* next = nullptr) : value(value), next(nullptr) {}
};

template<typename T>
class List
{
	ListNode<T>* head;

public:
	List() : head(nullptr) {}
	void add(T value)
	{
		ListNode<T>* n = new ListNode<T>(value);
		if (!head)
			head = n;
		else
		{
			n->next = head;
			head = n;
		}
	}
	void print()
	{
		ListNode<T>* tmp = head;
		while (tmp) {
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}
};




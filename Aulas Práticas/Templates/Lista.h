#pragma once
#include <string>

using namespace std;

template<typename T>
class List;

template<typename T>
class Node
{
	friend List<T>;
	T value;
	Node* next;
public:
	Node(T& value) : value(value) , next(nullptr) {}
};

template<typename T>
class List
{
	Node<T>* head;
public:
	List() : head(nullptr) {}
	bool isEmpty()
	{
		if (!head)
			return true;
		return false;
	}
	void push_back(T& value)
	{
		Node<T>* n = new Node<T>(value);
		if (isEmpty) {
			head = n;
			return;
		}
		Node<T>* ant = head;
		Node<T>* tmp = head;
		while (tmp->next) {
			ant = head;
			tmp = tmp->next;
		}
		n->next = nullptr;
		ant->next = n;
	}
	void push_front(T& value)
	{
		Node<T>* n = new Node<T>(value);
		if (isEmpty) {
			head = n;
			return;
		}
		n->next = head;
		head = n;
	}
	T pop_back()
	{
		Node<T>* ant = head;
		Node<T>* tmp = head;
		while (tmp->next) {
			ant = head;
			tmp = tmp->next;
		}
		delete ant;
		ant->next = nullptr;
	}
	T pop_front()
	{
		Node<T>* tmp = head->next;
		head = tmp;
		delete tmp;
		tmp->next = nullptr;
	}
	bool find(T& value) const
	{
		Node<T>* tmp = head;
		while (tmp)
		{
			if (tmp->value == value)
				return true;
			tmp = tmp->next;
		}
		return false;
	}
	void print() const
	{
		Node<T>* tmp = head;
		while (tmp)
		{
			cout << tmp->value << endl;
		}
	}
};


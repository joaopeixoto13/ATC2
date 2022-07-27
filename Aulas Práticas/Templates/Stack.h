#pragma once

template<typename T>
class Stack
{
	T* buffer;
	size_t _size;
	size_t pos;

public:
	Stack(size_t size) : _size(size), pos(0)
	{
		buffer = new T[_size];
	}
	~Stack()
	{
		delete[] buffer;
	}

	bool isEmpty() const
	{
		if (pos == 0)
			return true;
		return false;
	}

	bool isFull() const
	{
		if(pos == _size - 1)
			return true;
		return false;
	}

	bool push(const T& item)
	{
		if (isFull())
			return false;
		buffer[pos++] = item;
		return true;
	}

	bool pop(T& item)
	{
		if (isEmpty())
			return false;
		item = buffer[--pos];
		return true;
	}

	void print()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty" << endl;
			return;
		}
		for (size_t i = 0; i < pos; i++)
			cout << buffer[i] << endl;
	}

};

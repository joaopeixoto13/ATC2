#pragma once
#include "Base.h"

class Octal : public Base
{
	int value;
public:
	Octal(int value) : value(value) {}
	string toString();
};


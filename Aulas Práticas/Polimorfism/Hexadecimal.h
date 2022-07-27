#pragma once
#include "Base.h"

class Hexadecimal : public Base
{
	int value;
public:
	Hexadecimal(int value) : value(value) {}
	string toString();
};


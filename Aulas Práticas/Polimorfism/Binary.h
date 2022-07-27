#pragma once
#include "Base.h"

class Binary : public Base
{
	int value;
public:
	Binary(int value) : value(value) {}
	string toString();
};


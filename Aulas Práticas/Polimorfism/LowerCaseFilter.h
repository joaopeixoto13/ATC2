#pragma once
#include "BaseFilter.h"

class LowerCaseFilter : public BaseFilter
{
public:
	string apply(string& line);
};


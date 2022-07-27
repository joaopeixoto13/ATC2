#pragma once
#include "BaseFilter.h"

class UpperCaseFilter : public BaseFilter
{
public:
	string apply(const string& input);
};

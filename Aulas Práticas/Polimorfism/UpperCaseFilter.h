#pragma once
#include "BaseFilter.h"

class UpperCaseFilter : public BaseFilter
{
	string apply(string& line);
};


#pragma once
#include "BaseFilter.h"
#include <string>

using namespace std;

class RemoveSpacesFilter : public BaseFilter
{
	string apply(string& line);
};


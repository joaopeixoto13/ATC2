#pragma once
#include <string>

using namespace std;

class BaseFilter
{
public:
	virtual string apply(string& line) = 0;
};

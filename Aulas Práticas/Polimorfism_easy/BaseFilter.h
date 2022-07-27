#pragma once
#include <string>
using namespace std;

class BaseFilter
{
public:
	virtual string apply(const string& input) = 0;
};

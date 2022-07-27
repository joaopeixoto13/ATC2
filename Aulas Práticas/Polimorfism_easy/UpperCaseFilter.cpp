#include "UpperCaseFilter.h"

string UpperCaseFilter::apply(const string& input)
{
	string result;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
			result += input[i] - 32;
		else
			result += input[i];
	}
	return result;
}
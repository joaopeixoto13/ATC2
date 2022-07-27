#include "UpperCaseFilter.h"

string UpperCaseFilter::apply(string& line)
{
	string output;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] >= 'a' && line[i] <= 'z')
			output += line[i] - 32;
		else
			output += line[i];
	}
	return output;
}

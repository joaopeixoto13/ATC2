#include "LowerCaseFilter.h"

string LowerCaseFilter::apply(string& line)
{
	string output;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] >= 'A' && line[i] <= 'Z')
			output += line[i] + 32;
		else
			output += line[i];
	}
	return output;
}



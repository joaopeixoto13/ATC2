#include "RemoveSpacesFilter.h"

string RemoveSpacesFilter::apply(string& line)
{
	string output;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != ' ')
			output += line[i];
	}
	return output;
}

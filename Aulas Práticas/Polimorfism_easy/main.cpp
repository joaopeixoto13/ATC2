#include <iostream>
#include <vector>
#include <string>
#include "BaseFilter.h"
#include "UpperCaseFilter.h"

using namespace std;

typedef string (*func_t)(const string& input);


string lowerCaseFilter(const string& input)
{
	string result;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
			result += input[i] + 32;
		else
			result += input[i];
	}
	return result;
}

string removeSpacesFilter(const string& input)
{
	string result;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != ' ')
			result += input[i];
	}
	return result;
}

int main()
{
	string input, result;
	
	cout << "Introduza a string de entrada: ";
	getline(cin, input);
	/*
	vector<func_t> filters;
	filters.push_back(upperCaseFilter);
	filters.push_back(removeSpacesFilter);
	filters.push_back(lowerCaseFilter);

	for (int i = 0; i < filters.size(); i++)
		input = filters[i](input);

	cout << input << endl;*/

	vector<BaseFilter*> filters;
	filters.push_back(new UpperCaseFilter);

	for (int i = 0; i < filters.size(); i++)
		input = filters[i]->apply(input);

	cout << input;

	return 0;
}
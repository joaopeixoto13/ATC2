#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Student
{
	int number;
	string name;
	string email;
};


class BaseFormat
{
public:
	virtual string write(const Student& st) = 0;
};


class CsvFormat : public BaseFormat
{
public:
	string write(const Student& st)
	{
		return to_string(st.number) + ";" + st.name + ";" + st.email + ";";
	}
};


class XmlFormat : public BaseFormat
{
public:
	string write(const Student& st)
	{
		return "<student>\n <number>" + to_string(st.number) + 
			   "</number>\n <name>" + st.name + "</name>\n <email>" +
			   st.email + "</email>\n</student>\n";
	}
};
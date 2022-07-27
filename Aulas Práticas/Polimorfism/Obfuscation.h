#pragma once
#include <string>

using namespace std;

class Obfuscation
{
public:
	virtual void obfuscateLine(string& line) = 0;
	virtual void deobfuscateLine(string& line) = 0;
};


class Add10 : public Obfuscation
{
public:
	void obfuscateLine(string& line)
	{
		for (int i = 0; i < line.size(); i++)
			line[i] += 10;
		line.append("\n");
	}

	void deobfuscateLine(string& line)
	{
		for (int i = 0; i < line.size(); i++)
			line[i] -= 10;
		line.append("\n");
	}
};

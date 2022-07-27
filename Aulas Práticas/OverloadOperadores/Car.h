#pragma once
#include <string>
#include <iostream>

using namespace std;

class Car
{
	string regist;
	int spots;
	string color;
	int year;

public:
	Car(const string& regist, int spots, const string& color, int year)
		: regist(regist) , spots(spots), color(color), year(year) 
	{ }

	friend ostream& operator<<(ostream& oss, const Car& car)
	{
		oss << "Matricula: " << car.regist << "\nNumero de lugares: " << car.spots << "\nCor: " << car.color << "\nAno de Fabrico: " << car.year;
		return oss;
	}

	friend istream& operator>>(istream& iss, const Car& car)
	{
		iss >> car;
		return iss;
	}

	bool operator==(const Car& car)
	{
		if (regist == car.regist)
			return true;
		return false;
	}

	Car operator=(const Car& car)
	{
		regist = car.regist;
		spots = car.spots;
		color = car.color;
		year = car.year;
		return Car(regist, spots, color, year);
	}

	Car operator+(const Car& car)
	{
		regist += car.regist;
		spots += car.spots;
		color += car.color;
		year += car.year;
		return Car(regist, spots, color, year);
	}

	Car operator++()								//prefix
	{
		regist += regist;
		spots += spots;
		color += color;
		year += year;
		return Car(regist, spots, color, year);
	}

	Car operator++(int)								//posfix
	{
		regist += regist;
		spots += spots;
		color += color;
		year += year;
		return Car(regist, spots, color, year);
	}

};

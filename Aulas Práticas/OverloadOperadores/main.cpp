#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

class Student
{
	string name;
	int number;
	float average;

public:
	Student()
		: name(""), number(0), average(0)
	{ }
	Student(const string& name, int number, float average)
		: name(name), number(number), average(average)
	{ }
	bool operator==(const Student& st) {
		if (name == st.name && number == st.number && average == st.average)
			return true;
		return false;
	}
	Student operator=(const Student& st) {
		name = st.name;
		number = st.number;
		average = st.average;
		return Student(name, number, average);
	}
	Student operator+(const Student& st) {
		return Student(name + st.name, (number + st.number) / 2, (average + st.average) / 2);
	}
	friend ostream& operator<<(ostream& os, const Student& st) {
		os << "Name: " << st.name << "\nNumber: " << st.number << "\nAverage: " << st.average << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Student& st) {
		is >> st.name >> st.number >> st.average;
		return is;
	}

	Student operator+=(const Student& st) {
		name += st.name;
		number += number;
		average += average;
		return *this;
	}
};

class Point2D
{
	float x;
	float y;

public:
	Point2D()
		: x(0.0), y(0.0)
	{ }
	Point2D(float x, float y)
		: x(x), y(y)
	{ }
	Point2D& operator++() {
		x++;
		y++;
		return *this;
	}
	Point2D operator++(int) {
		++x;
		++y;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Point2D& p) {
		os << "{" << p.x << ", " << p.y << "}" << endl;
		return os;
 	}
};


int main()
{
	/*Student st1("Joao", 91960, 19.3F);
	Student st2("Maria", 91089, 15.47F);
	Student st3("Carlos", 89765, 17.88F);
	Student st4("Joao", 91960, 19.3F);

	cout << st1 << st2 << st3 << endl << endl;

	if (st1 == st2)
		cout << "Iguais" << endl;
	else
		cout << "Diferentes" << endl;

	if (st1 == st4)
		cout << "Iguais" << endl;
	else
		cout << "Diferentes" << endl;

	Student st5 = st1;
	cout << st5 << endl;

	Student st6 = st2 + st3;
	cout << st6 << endl;

	/*Student st7;
	cin >> st7;
	cout << st7;*/

	/*st1 += st2;
	cout << st1 << endl;

	
	Point2D p1(2.1F, 3.3F);
	cout << p1 << endl;

	cout << p1++ << endl;
	cout << ++p1 << endl;*/

	Car c1("AA-11-BB", 5, "branco", 2016);
	cout << c1 << endl << endl;

	Car c2("DE-11-FF", 3, "cinzento", 2019);
	Car c3("AA-11-BB", 5, "branco", 2016);

	if (c1 == c2)
		cout << "Equal" << endl;
	else
		cout << "Not Equal" << endl;

	if (c1 == c3)
		cout << "Equal" << endl << endl;
	else
		cout << "Not Equal" << endl;

	c1 = c2;
	cout << c1 << endl << endl;

	c1 = c3;

	c1 = c1 + c2 + c3;
	cout << c1 << endl << endl;

	cout << c1++ << endl << endl;

	return 0;
}

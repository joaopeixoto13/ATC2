#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;


int main()
{
	HashTable ht(5);
	ht.dump();

	Student st1 = { 19440, "Nuno Cardoso" };
	Student st2 = { 19441, "Nuno Cardoso" };
	Student st3 = { 19444, "Nuno Cardoso" };
	Student st4 = { 19434, "Pedro Ribeiro" };

	ht.add(st1);
	ht.add(st2);
	ht.add(st3);
	ht.add(st4);
	ht.dump();

	cout << "size: " << ht.size() << endl;
	cout << "occupied: " << ht.loadFactor() << "%" << endl;

	try {
		cout << "name: " << ht.name(19444) << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	ht.remove(19441);
	ht.dump();

	cout << "size: " << ht.size() << endl;
	cout << "occupied: " << ht.loadFactor() << "%" << endl;


	return 0;
}




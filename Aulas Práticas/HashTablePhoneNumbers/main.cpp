#include <iostream>
#include <iostream>
#include "HashTable.h"

using namespace std;


int main()
{
	HashTable phone(200);

    try {
        phone.add("jose", 919293949);
        phone.add("joao", 911922933);
        phone.add("maria", 922933944);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    string name;
    long number;
    cin >> name;
    try {
        number = phone.number(name);
        cout << number << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    cin >> name;
    if (phone.remove(name))
        cout << "Removido!\n";
    else
        cout << "Nao existe!\n";

    cout << phone.size() << endl;
    cout << phone.loadFactor() << endl;
	return 0;
}
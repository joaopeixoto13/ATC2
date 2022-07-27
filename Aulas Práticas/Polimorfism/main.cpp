#include "BaseFilter.h"
#include "LowerCaseFilter.h"
#include "UpperCaseFilter.h"
#include "RemoveSpacesFilter.h"
#include "Base.h"
#include "Octal.h"
#include "Hexadecimal.h"
#include "Binary.h"
#include "BaseFormat.h"
#include "Veiculo.h"
#include <vector>
#include <iostream>

using namespace std;


int main()
{
	/*string input;
	cout << "Introduza a string de entrada: ";
	getline(cin, input);

	vector<BaseFilter*> filters;

	filters.push_back(new UpperCaseFilter);
	filters.push_back(new RemoveSpacesFilter);

	cout << "Initial input: " << input << endl;

	for (int i = 0; i < filters.size(); i++)
	{
		input = filters[i]->apply(input);
		cout << i + 1 << " filter: " << input << endl;
	}*/


	/*vector<Base*> values;
	values.push_back(new Octal(10));
	values.push_back(new Hexadecimal(10));
	values.push_back(new Binary(10));
	values.push_back(new Octal(20));
	values.push_back(new Hexadecimal(20));
	values.push_back(new Binary(20));

	for (int i = 0; i < values.size(); i++)
		cout << values[i]->toString() << endl;*/


	/*Student student = { 19444, "Nuno Cardoso", "linun77@gmail.com" };

	vector<BaseFormat*> baseFormats;
	baseFormats.push_back(new CsvFormat);
	baseFormats.push_back(new XmlFormat);

	for (int i = 0; i < baseFormats.size(); i++)
		cout << baseFormats[i]->write(student) << endl << endl;*/

	vector<Veiculo*> veiculo;
	veiculo.push_back(new Automovel);
	veiculo.push_back(new Camiao);
	veiculo.push_back(new Mota);

	for (int i = 0; i < veiculo.size(); i++) {
		veiculo[i]->appendKm(10);
		cout << "Numero de km: " << veiculo[i]->km() << endl;
	}

	int totalKm = 0;
	for (int i = 0; i < veiculo.size(); i++)
		totalKm += veiculo[i]->km();
	cout << "Numero total de km da frota: " << totalKm << endl;


	return 0;
}

#include <iostream>
//#include "List.h"
#include "BinTree.h"
#include "HashTable.h"
#include "Stack.h"
#include <sstream>
#include "Lista.h"

using namespace std;

template<typename T>
T add(T a, T b)
{
	return a + b;
}

template<typename Tint, typename Tfloat>
Tfloat add(Tint a, Tfloat b)
{
	return a + b;
}



int main()
{
	/*cout << add(1, 2) << endl;

	List<int> IntList;
	IntList.add(1);
	IntList.add(2);
	IntList.add(3);
	IntList.add(4);

	IntList.print();*/

	/*BinTree<string> IntegerTree;

	IntegerTree.add("ddd");
	IntegerTree.add("ccc");
	IntegerTree.add("eee");
	IntegerTree.add("aaa");
	IntegerTree.add("bbb");
	IntegerTree.add("kkk");

	vector<string>elements = IntegerTree.inOrder();

	for (auto i : elements)
		cout << i << " ";*/


	/*HashTable<Student> table(5);

	table.add({ 1, "aaa" });
	table.add({ 3, "ccc" });
	table.add({ 2, "bbb" });
	table.add({ 4, "ddd" });

	table.print();

	table.remove({ 2, "bbb" });

	table.print();*/


	Stack<float> floatStack(5);
	float popValue;

	floatStack.print();
	if (!floatStack.push(1.1F))
		cout << "Stack is Full" << endl;
	if (!floatStack.push(2.1F))
		cout << "Stack is Full" << endl;
	if (!floatStack.push(3.8F))
		cout << "Stack is Full" << endl;
	floatStack.print();
	if (!floatStack.pop(popValue))
		cout << "Stack is Empty" << endl;
	else
		cout << "Pop " << popValue << " successful" << endl;
	if (!floatStack.pop(popValue))
		cout << "Stack is Empty" << endl;
	else
		cout << "Pop " << popValue << " successful" << endl;
	if (!floatStack.pop(popValue))
		cout << "Stack is Empty" << endl;
	else
		cout << "Pop " << popValue << " successful" << endl;
	if (!floatStack.pop(popValue))
		cout << "Stack is Empty" << endl;
	else
		cout << "Pop " << popValue << " successful" << endl;


	



	return 0;
}
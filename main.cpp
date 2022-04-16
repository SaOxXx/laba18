#include <iostream>
#include <map>
#include <list>
#include "multimap.h"
using namespace std;

int main()
{	Multimap a;
	Multimap b;
	Multimap c;
	Multimap d;
	cout << "Input list:" << endl;
	a.insert("a",1);
	a.insert("c", 2);
	a.insert("b", 3);
	a.insert("d", 4);
	a.insert("e", 1);
	a.insert("f", 1);
	a.insert("f", 222);
	a.insert("f", 3);
	a.insert("a", 4);
	a.insert("s", 1);
	a.insert("c", 2);
	a.insert("b", 3);
	a.erase("b");
	b.insert("a", 4);
	b.insert("a", 90);
	b.insert("c", 1);
	b.insert("c", 2);
	b.insert("z", 88);
	b.insert("z", 76);
	c = a+b;
	cout << c << endl;
	d += c;
	cout << d << endl;
	//cout << a << endl;
	//cout << b << endl;
	//a += c;
	//cout << a;

	return 0;
}
#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction f1(11, -3);
	Fraction f2;
	cout << "Fraction #1 = ";
	f1.Show();
	cout << "Fraction #2 = ";
	f2.Show();
	cout << "Fraction #1 / Fraction #2 = ";
	(f1 / f2).Show();
	cout << "Fraction #2 = ";
	(f2 = { 3, 2 }).Show();
	cout << "Fraction #1 + Fraction #2 = ";
	(f1 + f2).Show();
	cout << "Fraction #1 + 7 = ";
	(f1 + 7).Show();
	cout << "Fraction #1 - Fraction #2 = ";
	(f1 - f2).Show();
	cout << "Fraction #1 * Fraction #2 = ";
	(f1 * f2).Show();
	cout << "Fraction #1 * 7 = ";
	(f1 * 7).Show();
	cout << "Fraction #1 / Fraction #2 = ";
	(f1 / f2).Show();
	cout << "Fraction #1 == Fraction #2 = ";
	cout << boolalpha << (f1 == f2) << endl;
	cout << "Fraction #1 != Fraction #2 = ";
	cout << boolalpha << (f1 != f2) << endl;
	cout << "Fraction #1 > Fraction #2  = ";
	cout << boolalpha << (f1 > f2) << endl;
	cout << "Fraction #1 < Fraction #2  = ";
	cout << boolalpha << (f1 < f2) << endl;

	system("pause");
	return 0;
}
#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction f1(5);
	Fraction f2(10, -3);
	f1.Show();
	f2.Show();
	Fraction f3 = f1 + f2;
	f3.Show();
	f3 = f1 - f2;
	f3.Show();
	Fraction f4 = f3 + 5;
	f4.Show();
	Fraction f5 = f3 * 5;
	f5.Show();
	Fraction f6;
	f6.Show();
	(f1 / f6).Show();
	cout << boolalpha << (f1 == f2) << endl;
	cout << boolalpha << (f1 != f2) << endl;
	
	system("pause");
	return 0;
}
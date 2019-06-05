#include <iostream>
#include "Reservoir.h"
using namespace std;

int main()
{
	Reservoir res1;
	Reservoir res2("www", noType, 5, 3, 2);
	res1.ShowFullInfo();
	//cout << Reservoir::GetReservoirCount() << endl;
	cout << boolalpha << Reservoir::SameResType(res1, res2) << endl;
	cout << Reservoir::GetBiggerAreaRes(res1, res2) << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include "Reservoir.h"
using namespace std;

int main()
{
	const int SIZE = 3;
	Reservoir* arr[SIZE] = {
		new Reservoir(),
		new Reservoir("Res2", lake, 5, 3, 2),
		new Reservoir("Res3", lake, 7, 6, 3) };

	for (int i = 0; i < Reservoir::GetReservoirCount(); i++)
	{
		arr[i]->ShowFullInfo();
	}
	cout << "\nRes2 and Res3 have same reservoir type? ";
	cout << boolalpha << Reservoir::SameResType(*arr[1], *arr[2]) << endl;
	cout << "Bigger reservoir of Res2 and Res3(1 - Res2, 0 - equal, -1 - Res3): ";
	cout << Reservoir::GetBiggerAreaRes(*arr[1], *arr[2]) << endl;
	cout << "Index of the biggest reservoir in array: ";
	cout << Reservoir::GetBiggestFromArray(arr, lake) << endl;
	system("pause");
	return 0;
}
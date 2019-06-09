#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "Fish.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	int turn = 0;
	int meal = 2;
	Fish* fishes = new Fish[5];
	while (Fish::GetFishQuantity())
	{
		system("cls");
		if (turn % 25 == 0)
		{
			Fish::Feed(meal);
			turn++;
		}
		for (int i = 0; i < 5; i++)
		{
			cout << "Fish #" << i + 1 << ": ";
			fishes[i].ShowFish();
		}
		for (int x = -1; x < 11; x++)
		{
			for (int y = -1; y < 11; y++)
			{
				if ((x < 0 || x > 9) || (y < 0 || y > 9))
					cout << '#';
				else
					cout << Fish::GetCell(x, y);
				cout << ' ';
			}
			cout << endl;
		}
		for (int i = 0; i < 5; i++)
		{
			fishes[i].Move();
		}
		Sleep(100);
	};
	delete[] fishes;
	cout << "Sorry, all fishes are dead.\n";
	system("pause");
	return 0;
}
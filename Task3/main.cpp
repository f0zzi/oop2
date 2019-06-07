#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "Fish.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	int hp = 50, meal = 5;
	Fish fish1(5, 5, hp);
	Fish fish2(5, 5, hp);
	Fish fish3(5, 5, hp);
	Fish fish4(5, 5, hp);
	Fish fish5(5, 5, hp);

	for (int i = 0; i < 200; i++)
	{
		system("cls");
		if (i % 10 == 0)
			Fish::Feed(meal);
		fish1.ShowFish();
		fish2.ShowFish();
		fish3.ShowFish();
		fish4.ShowFish();
		fish5.ShowFish();
		for (int x = -1; x < 11; x++)
		{
			for (int y = -1; y < 11; y++)
			{
				if ((x < 0 || x > 9) || (y < 0 || y > 9))
					cout << '#';
				else
					cout << Fish::GetCell(x, y);
			}
			cout << endl;
		}
		fish1.Move();
		fish2.Move();
		fish3.Move();
		fish4.Move();
		fish5.Move();
		Sleep(50);
	}
	system("pause");
	return 0;
}
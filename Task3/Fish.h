#pragma once
#include <iostream>
using namespace std;
class Fish
{
private:
	int x, y;
	int hp;
	char fishId;
	static const int SIZE = 10;
	static char sea[][SIZE];
	static int fishQuantity;
public:
	Fish() : Fish((rand() % SIZE), (rand() % SIZE), 50) {}
	Fish(int x, int y, int hp) :x(x), y(y), hp(hp)
	{
		fishId = (char)((++fishQuantity) + 48);
		sea[x][y] = fishId;
	}
	int GetX() const
	{
		return x;
	}
	int GetY() const
	{
		return y;
	}
	int GetHp() const
	{
		return hp;
	}
	void ShowFish() const
	{
		if (hp > 0)
			cout << "Coords[" << x << "][" << y << "]  HP: " << hp << endl;
		else
			cout << "dead.\n";
	}
	void Move()
	{
		sea[x][y] = ' ';
		if (hp > 0) {
			switch ((rand() % 8) + 1)
			{
			case 1:
				if (x > 0)
					x--;
				if (y > 0)
					y--;
				break;
			case 2:
				if (y > 0)
					y--;
				break;
			case 3:
				if (x < SIZE - 1)
					x++;
				if (y > 0)
					y--;
				break;
			case 4:
				if (x < SIZE - 1)
					x++;
				break;
			case 5:
				if (x < SIZE - 1)
					x++;
				if (y < SIZE - 1)
					y++;
				break;
			case 6:
				if (y < SIZE - 1)
					y++;
				break;
			case 7:
				if (x > 0)
					x--;
				if (y < SIZE - 1)
					y++;
				break;
			case 8:
				if (x > 0)
					x--;
				break;
			}
			if (sea[x][y] == 'F')
				hp += 50;
			sea[x][y] = fishId;
			hp--;
		}
		if (hp == 0)
		{
			sea[x][y] = ' ';
			fishQuantity--;
			hp--;
		}
	}
	static char GetCell(int x, int y)
	{
		return sea[x][y];
	}
	static void Feed(int size)
	{
		int x, y;
		for (int i = 0; i < size; i++)
		{
			do
			{
				x = rand() % 10;
				y = rand() % 10;
			} while (sea[x][y] != ' ');
			sea[x][y] = 'F';
		}
	}
	static int GetFishQuantity()
	{
		return fishQuantity;
	}
	static void ShowFishesInfo(Fish* fishes, int quantity)
	{
		for (int i = 0; i < quantity; i++)
		{
			cout << "Fish #" << i + 1 << ": ";
			fishes[i].ShowFish();
		}
	}
	static void ShowSea()
	{
		for (int x = -1; x < SIZE + 1; x++)
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
	}
	static void StartFishes(Fish* fishes, int meal, int frequency)
	{
		int turn = 1;
		int quantity = fishQuantity;
		while (fishQuantity)
		{
			system("cls");
			if (turn % frequency == 0)
				Fish::Feed(meal);
			turn++;

			for (int i = 0; i < 5; i++)
			{
				fishes[i].Move();
			}
			Fish::ShowFishesInfo(fishes, quantity);
			Fish::ShowSea();
			Sleep(100);
		};
		cout << "Sorry, all fishes are dead.\n";
	}
};
int Fish::fishQuantity = 0;
char Fish::sea[10][10] = { ' ' };
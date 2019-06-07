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
	static char arr[][SIZE];
	static int fishQuantity;
public:
	Fish(int x, int y, int hp) :x(x), y(y), hp(hp)
	{
		fishId = (char)((++fishQuantity) + 48);
		arr[x][y] = fishId;
	}
	int GetX() const
	{
		return x;
	}
	int GetY() const
	{
		return y;
	}
	void ShowFish() const
	{
		cout << "Coords[" << x << "][" << y << "]  HP: " << hp << endl;
	}
	void Move()
	{
		arr[x][y] = ' ';
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
			if (arr[x][y] == 'F')
				hp += 50;
			arr[x][y] = fishId;
			hp--;
		}
	}
	static char GetCell(int x, int y)
	{
		return arr[x][y];
	}
	static void Feed(int size)
	{
		int x, y;
		for (int i = 0; i < size; i++)
		{
			x = rand() % 10;
			y = rand() % 10;
			if (arr[x][y] == ' ')
				arr[x][y] = 'F';
		}
	}
};
int Fish::fishQuantity = 0;
char Fish::arr[10][10] = { ' ' };
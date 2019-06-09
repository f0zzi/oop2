#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "Fish.h"
using namespace std;

int main()
{
	srand(time(nullptr));
	Fish* fishes = new Fish[5];
	int meal = 2; // amount of food given to fishes
	int frequency = 40; // number of turns you feed fishes
	Fish::StartFishes(fishes, meal, frequency);
	delete[] fishes;
	system("pause");
	return 0;
}
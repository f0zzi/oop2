#pragma once
#include <iostream>
#include <cstring>
using namespace std;
enum ResType { noType, lake, sea, ocean };

class Reservoir
{
private:
	char* name;
	ResType type;
	int width, length, depth;
	static int reservoirCount;
public:
	Reservoir() : Reservoir("No name", noType, 1, 1, 1) {};
	Reservoir(const char* name, ResType type, int width, int length, int depth) :
		width(width), length(length), depth(depth), type(type)
	{
		SetName(name);
		reservoirCount++;
	}
	void SetName(const char* name)
	{
		if (this->name != nullptr)
			delete[] this->name;
		int size = strlen(name) + 1;
		this->name = new char[size];
		strcpy_s(this->name, size, name);
	}
	void SetWidth(int width)
	{
		if (width <= 0)
		{
			cout << "Invalid width. Should be bigger than 0.\n";
			system("pause");
		}
		else
			this->width = width;
	}
	void SetLength(int length)
	{
		if (length <= 0)
		{
			cout << "Invalid width. Should be bigger than 0.\n";
			system("pause");
		}
		else
			this->length = length;
	}
	void SetDepth(int depth)
	{
		if (depth <= 0)
		{
			cout << "Invalid width. Should be bigger than 0.\n";
			system("pause");
		}
		else
			this->depth = depth;
	}
	static int GetReservoirCount()
	{
		return reservoirCount;
	}
	void ShowFullInfo() const
	{
		cout << "Name: " << GetName();
		cout << "  Type: ";
		switch (GetResType())
		{
		case 0:
			cout << "No type";
			break;
		case 1:
			cout << "lake";
			break;
		case 2:
			cout << "sea";
			break;
		case 3:
			cout << "ocean";
			break;
		default:
			cout << "Error.";
			break;
		}
		cout << "  Volume: " << GetVolume() << "  Area: " << GetArea() << endl;
	}
	const char* GetName() const
	{
		return this->name;
	}
	int GetWidth() const
	{
		return this->width;
	}
	int GetLength() const
	{
		return this->length;
	}
	int GetDepth() const
	{
		return this->depth;
	}
	ResType GetResType() const
	{
		return this->type;
	}
	int GetVolume() const
	{
		return this->width * this->length * this->depth;
	}
	int GetArea() const
	{
		return this->width * this->length;
	}
	static bool SameResType(const Reservoir& first, const Reservoir& second)
	{
		return first.GetResType() == second.GetResType();
	}
	static int GetBiggerAreaRes(const Reservoir& first, const Reservoir& second)
	{
		if (first.GetArea() > second.GetArea())
			return 1;
		else if (first.GetArea() < second.GetArea())
			return -1;
		else
			return 0;
	}
	static int GetBiggestAreaRes(const Reservoir* arr, ResType type)
	{
		int index = -1;
		int maxArea = 0;
		for (int i = 0; i < Reservoir::GetReservoirCount(); i++)
		{
			if (arr[i].GetResType() == type)
			{
				if (arr[i].GetArea() > maxArea)
				{
					index = i;
					maxArea = arr[i].GetArea();
				}
			}
		}
		return index;
	}
};
int Reservoir::reservoirCount = 0;
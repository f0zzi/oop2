#include "Reservoir.h"

int Reservoir::reservoirCount = 0;

Reservoir::Reservoir(const char* name, ResType type, int width, int length, int depth)
	: type(type)
{
	SetWidth(width);
	SetLength(length);
	SetDepth(depth);
	SetName(name);
	reservoirCount++;
}
Reservoir::~Reservoir()
{
	if (name != nullptr)
		delete[] name;
}
void Reservoir::SetName(const char* name)
{
	if (this->name != nullptr)
		delete[] this->name;
	int size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

void Reservoir::SetWidth(int width)
{
	if (width <= 0)
	{
		cout << "Invalid width. Should be bigger than 0. Set to one.\n";
		this->width = 1;
		system("pause");
	}
	else
		this->width = width;
}

void Reservoir::SetLength(int length)
{
	if (length <= 0)
	{
		cout << "Invalid width. Should be bigger than 0. Set to one.\n";
		this->length = 1;
		system("pause");
	}
	else
		this->length = length;
}

void Reservoir::SetDepth(int depth)
{
	if (depth <= 0)
	{
		cout << "Invalid width. Should be bigger than 0. Set to one.\n";
		this->depth = 1;
		system("pause");
	}
	else
		this->depth = depth;
}

void Reservoir::ShowFullInfo() const
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

bool Reservoir::SameResType(const Reservoir& first, const Reservoir& second)
{
	return first.GetResType() == second.GetResType();
}

int Reservoir::GetBiggerAreaRes(const Reservoir& first, const Reservoir& second)
{
	if (first.GetArea() > second.GetArea())
		return 1;
	else if (first.GetArea() < second.GetArea())
		return -1;
	else
		return 0;
}

int Reservoir::GetBiggestFromArray(Reservoir** arr, ResType type)
{
	int size = Reservoir::GetReservoirCount();
	int index = -1;
	int maxArea = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->GetResType() == type)
		{
			if (arr[i]->GetArea() > maxArea)
			{
				index = i;
				maxArea = arr[i]->GetArea();
			}
		}
	}
	return index;
}

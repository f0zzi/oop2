#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) :numerator(numerator)
{
	SetDenom(denominator);
}

void Fraction::SetDenom(int denominator)
{
	if (denominator == 0)
	{
		this->denominator = 1;
		return;
	}
	this->denominator = denominator;
	if (denominator < 0)
	{
		this->numerator *= -1;
		this->denominator = -this->denominator;
	}
}

void Fraction::Show()
{
	if (denominator > 1)
		this->Normalize();
	cout << numerator;
	if (denominator != 1 && numerator != 0)
		cout << "/" << denominator;
	cout << endl;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	if (other.numerator == 0)
	{
		cout << "Error. Division by zero. Result is reset to zero.\n";
		system("pause");
		return Fraction();
	}
	else
		return Fraction(this->numerator * other.denominator, this->denominator * other.numerator);
}

void Fraction::Normalize()
{
	int tmp = (numerator < 0 ? -numerator : numerator);
	int min = (tmp < denominator ? tmp : denominator);
	int divider = 1;
	for (int i = 2; i <= min; i++)
	{
		if (numerator % i == 0 && denominator % i == 0)
			divider = i;
	}
	if (divider > 1)
	{
		numerator /= divider;
		denominator /= divider;
	}
}
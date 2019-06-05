#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator = 0;
	int denominator = 1;

public:
	Fraction() = default;
	Fraction(int numerator, int denominator);
	Fraction(int numerator) :numerator(numerator) {}

	void SetDenom(int denominator);

	void SetNum(int numerator)
	{
		this->numerator = numerator;
	}
	void Show();

	Fraction operator+(const Fraction& other) const
	{
		return Fraction(this->numerator * other.denominator + this->denominator * other.numerator, this->denominator * other.denominator);
	}
	Fraction operator +(int number) const
	{
		return Fraction(this->numerator + this->denominator * number, this->denominator);
	}
	Fraction operator-(const Fraction& other) const
	{
		return Fraction(this->numerator * other.denominator - this->denominator * other.numerator, this->denominator * other.denominator);
	}
	Fraction operator*(const Fraction& other) const
	{
		return Fraction(this->numerator * other.numerator, this->denominator * other.denominator);
	}
	Fraction operator *(int number) const
	{
		return Fraction(this->numerator * number, this->denominator);
	}
	Fraction operator/(const Fraction& other) const;

	bool operator==(const Fraction& other) const
	{
		return this->numerator * other.denominator == this->denominator * other.numerator;
	}
	bool operator!=(const Fraction& other) const
	{
		return !(this->numerator * other.denominator == this->denominator * other.numerator);
	}
	bool operator>(const Fraction& other) const
	{
		return this->numerator * other.denominator > this->denominator * other.numerator;
	}
	bool operator<(const Fraction& other) const
	{
		return this->numerator * other.denominator < this->denominator * other.numerator;
	}
	void Normalize();
};
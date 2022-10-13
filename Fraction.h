#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>
class Fraction
{
private:
	int numerator_;

	int denominator_;

public:
	Fraction(int numerator, int denominator);

	int compare(const Fraction& other) const;

	bool operator == (const Fraction& other) const;

	bool operator != (const Fraction& other) const;

	bool operator >= (const Fraction& other) const;

	bool operator > (const Fraction& other) const;

	bool operator <= (const Fraction& other) const;

	bool operator < (const Fraction& other) const;
};



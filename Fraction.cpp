#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Знаменатель не должен быть равен нулю");
	}

	numerator_ = numerator;
	denominator_ = denominator;
}

int Fraction::compare(const Fraction& other) const
{
	int currentN = numerator_;
	int otherN = other.numerator_;
	if (denominator_ != other.denominator_)
	{
		currentN = currentN * other.denominator_;
		otherN = otherN * denominator_;
	}

	return currentN > otherN ? 1 : (currentN == otherN ? 0 : -1);
}

bool Fraction::operator == (const Fraction& other) const
{
	return compare(other) == 0;
}

bool Fraction::operator != (const Fraction& other) const
{
	return compare(other) != 0;
}

bool Fraction::operator >= (const Fraction& other) const
{
	return compare(other) >= 0;
}

bool Fraction::operator > (const Fraction& other) const
{
	return compare(other) > 0;
}

bool Fraction::operator <= (const Fraction& other) const
{
	return compare(other) <= 0;
}

bool Fraction::operator < (const Fraction& other) const
{
	return compare(other) < 0;
}
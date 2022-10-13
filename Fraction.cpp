#include "Fraction.h"


// Алгоритм евклида для нахождения НОД
int Fraction::getGcd(int v1, int v2)
{
	auto a = std::abs(v1);
	auto b = std::abs(v2);

	if (a == 0 || b == 0)
	{
		return 1;
	}
	auto large = a > b ? a : b;
	auto small = a > b ? b : a;
	do
	{
		auto r = large % small;
		if (r == 0)
		{
			return small;
		}

		large = small;
		small = r;
	} while (true);
}

Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Знаменатель не должен быть равен нулю");
	}

	numerator_ = numerator;
	denominator_ = denominator;
}

void Fraction::shorten()
{
	auto gcd = getGcd(numerator_, denominator_);
	numerator_ = numerator_ / gcd;
	denominator_ = denominator_ / gcd;
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
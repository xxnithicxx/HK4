#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        Fraction(numerator);
        return;
    }

    _numerator = numerator;
    _denominator = denominator;
}

Fraction::Fraction(int numerator)
{
    _numerator = numerator;
    _denominator = 1;
}

Fraction::Fraction()
{
    _numerator = 0;
    _denominator = 1;
}

Fraction::Fraction(const Fraction &other)
{
    _numerator = other._numerator;
    _denominator = other._denominator;
}
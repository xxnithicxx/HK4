#include "Fraction.h"
#include <iostream>
using namespace std;

void Fraction::Input()
{
    cout << "Enter numerator: ";
    cin >> _numerator;
    cout << "Enter denominator: ";
    cin >> _denominator;
}

void Fraction::Output()
{
    cout << _numerator << "/" << _denominator << endl;
}

Fraction Fraction::Add(Fraction other)
{
    Fraction result;
    result._numerator = _numerator * other._denominator + _denominator * other._numerator;
    result._denominator = _denominator * other._denominator;
    return result;
}

Fraction Fraction::Subtract(Fraction other)
{
    Fraction result;
    result._numerator = _numerator * other._denominator - _denominator * other._numerator;
    result._denominator = _denominator * other._denominator;
    return result;
}

Fraction Fraction::Multiply(Fraction other)
{
    Fraction result;
    result._numerator = _numerator * other._numerator;
    result._denominator = _denominator * other._denominator;
    return result;
}

Fraction Fraction::Divide(Fraction other)
{
    if (other._numerator == 0)
    {
        throw "Division by zero";
    }

    Fraction result;
    result._numerator = _numerator * other._denominator;
    result._denominator = _denominator * other._numerator;
    return result;
}

Fraction Fraction::Reduce()
{
    int a = _numerator;
    int b = _denominator;
    int c = 0;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    _numerator /= a;
    _denominator /= a;

    return *this;
}

int Fraction::Compare(Fraction other)
{
    int a = _numerator * other._denominator;
    int b = _denominator * other._numerator;
    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

bool Fraction::isPositive()
{
    return _numerator > 0 && _denominator > 0;
}

bool Fraction::isNegative()
{
    return _numerator < 0 && _denominator > 0;
}

bool Fraction::isZero()
{
    return _numerator == 0;
}
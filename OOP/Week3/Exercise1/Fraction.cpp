#include "Fraction.h"

Fraction::Fraction()
{
    _numerator = 0;
    _denominator = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        numerator = 0;
        denominator = 1;
    }
    _numerator = numerator;
    _denominator = denominator;
}

Fraction::Fraction(int numerator)
{
    _numerator = numerator;
    _denominator = 1;
}

Fraction::Fraction(const Fraction &other)
{
    _numerator = other._numerator;
    _denominator = other._denominator;
}

Fraction &Fraction::operator=(const Fraction &other)
{
    _numerator = other._numerator;
    _denominator = other._denominator;
    return *this;
}

Fraction Fraction::operator+(const Fraction &other)
{
    Fraction result;
    result._numerator = _numerator * other._denominator + _denominator * other._numerator;
    result._denominator = _denominator * other._denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator-(const Fraction &other)
{
    Fraction result;
    result._numerator = _numerator * other._denominator - _denominator * other._numerator;
    result._denominator = _denominator * other._denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator*(const Fraction &other)
{
    Fraction result;
    result._numerator = _numerator * other._numerator;
    result._denominator = _denominator * other._denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator/(const Fraction &other)
{
    Fraction result;
    if (other._numerator == 0)
    {
        throw logic_error("Division by zero");
    }
    else
    {
        result._numerator = _numerator * other._denominator;
        result._denominator = _denominator * other._numerator;
        result.simplify();
    }

    return result;
}

Fraction operator+(const int& num, const Fraction& other)
{
    Fraction result;
    result._numerator = num * other._denominator + other._numerator;
    result._denominator = other._denominator;
    result.simplify();
    return result;
}

Fraction operator+(const Fraction& other, const int& num)
{
    Fraction result;
    result._numerator = num * other._denominator + other._numerator;
    result._denominator = other._denominator;
    result.simplify();
    return result;
}

Fraction operator-(const int& num, const Fraction& other)
{
    Fraction result;
    result._numerator = num * other._denominator - other._numerator;
    result._denominator = other._denominator;
    result.simplify();
    return result;
}

Fraction operator-(const Fraction& other, const int& num)
{
    Fraction result;
    result._numerator = num * other._denominator - other._numerator;
    result._denominator = other._denominator;
    result.simplify();
    return result;
}

Fraction operator*(const int& num, const Fraction& other)
{
    Fraction result;
    result._numerator = num * other._numerator;
    result._denominator = other._denominator;
    result.simplify();
    return result;
}

Fraction operator*(const Fraction& other, const int& num)
{
    Fraction result;
    result._numerator = num * other._numerator;
    result._denominator = other._denominator;
    result.simplify();
    return result;
}

Fraction operator/(const int& num, const Fraction& other)
{
    Fraction result;
    if (other._numerator == 0)
    {
        throw logic_error("Division by zero");
    }
    else
    {
        result._numerator = num * other._denominator;
        result._denominator = other._numerator;
        result.simplify();
    }

    return result;
}

Fraction operator/(const Fraction& other, const int& num)
{
    Fraction result;
    if (num == 0)
    {
        throw logic_error("Division by zero");
    }
    else
    {
        result._numerator = num * other._denominator;
        result._denominator = other._numerator;
        result.simplify();
    }

    return result;
}

ostream &operator<<(ostream &os, const Fraction &fraction)
{
    if (fraction._denominator == 1)
    {
        os << fraction._numerator;
    }
    else
    {
        os << fraction._numerator << "/" << fraction._denominator;
    }
    return os;
}

bool Fraction::operator==(const Fraction &other)
{
    return _numerator * other._denominator == _denominator * other._numerator;
}

bool Fraction::operator!=(const Fraction &other)
{
    return !(*this == other);
}

bool Fraction::operator>(const Fraction &other)
{
    int first = _numerator * other._denominator;
    int second = _denominator * other._numerator;

    return ((first - second) * _denominator * other._denominator) > 0;
}

bool Fraction::operator<(const Fraction &other)
{
    int first = _numerator * other._denominator;
    int second = _denominator * other._numerator;

    return ((first - second) * _denominator * other._denominator) == 0;
}

bool Fraction::operator>=(const Fraction &other)
{
    return *this > other || *this == other;
}

bool Fraction::operator<=(const Fraction &other)
{
    return *this < other || *this == other;
}

Fraction& Fraction::operator++()
{
    _numerator += _denominator;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction result = *this;
    ++(*this);
    return result;
}

Fraction& Fraction::operator--()
{
    _numerator -= _denominator;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction result = *this;
    --(*this);
    return result;
}

Fraction& Fraction::operator+=(const Fraction &other)
{
    _numerator = _numerator * other._denominator + _denominator * other._numerator;
    _denominator = _denominator * other._denominator;
    simplify();
    return *this;
}

Fraction& Fraction::operator-=(const Fraction &other)
{
    _numerator = _numerator * other._denominator - _denominator * other._numerator;
    _denominator = _denominator * other._denominator;
    simplify();
    return *this;
}

Fraction& Fraction::operator*=(const Fraction &other)
{
    _numerator = _numerator * other._numerator;
    _denominator = _denominator * other._denominator;
    simplify();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction &other)
{
    if (other._numerator == 0)
    {
        throw logic_error("Division by zero");
    }
    else
    {
        _numerator = _numerator * other._denominator;
        _denominator = _denominator * other._numerator;
        simplify();
    }

    return *this;
}

Fraction::operator float() const
{
    return (float)_numerator / _denominator;
}

void Fraction::print()
{
    if (_denominator == 1)
    {
        cout << _numerator << endl;
    }
    else
    {
        cout << _numerator << "/" << _denominator << endl;
    }
}

void Fraction::simplify()
{
    int GCD = gcd(_numerator, _denominator);
    _numerator /= GCD;
    _denominator /= GCD;

    if (signbit(_denominator))
    {
        _numerator *= -1;
        _denominator *= -1;
    }
}

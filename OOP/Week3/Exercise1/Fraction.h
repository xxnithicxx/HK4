#pragma once

#include <iostream>
#include <numeric>
#include <stdexcept>
#include <cmath>
using namespace std;

class Fraction
{
private:
    int _numerator;
    int _denominator;

public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(int numerator);
    Fraction(const Fraction &other);

    Fraction &operator=(const Fraction &other);
    Fraction operator+(const Fraction &other);
    Fraction operator-(const Fraction &other);
    Fraction operator*(const Fraction &other);
    Fraction operator/(const Fraction &other);

    friend Fraction operator+(const Fraction &other, const int &num);
    friend Fraction operator+(const int &num, const Fraction &other);
    friend Fraction operator-(const Fraction &other, const int &num);
    friend Fraction operator-(const int &num, const Fraction &other);
    friend Fraction operator*(const Fraction &other, const int &num);
    friend Fraction operator*(const int &num, const Fraction &other);
    friend Fraction operator/(const Fraction &other, const int &num);
    friend Fraction operator/(const int &num, const Fraction &other);

    friend ostream &operator<<(ostream &os, const Fraction &fraction);

    bool operator==(const Fraction &other);
    bool operator!=(const Fraction &other);
    bool operator>=(const Fraction &other);
    bool operator<=(const Fraction &other);
    bool operator>(const Fraction &other);
    bool operator<(const Fraction &other);

    Fraction &operator+=(const Fraction &other);
    Fraction &operator-=(const Fraction &other);
    Fraction &operator*=(const Fraction &other);
    Fraction &operator/=(const Fraction &other);

    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);
    operator float() const;

    void simplify();
    void print();
};

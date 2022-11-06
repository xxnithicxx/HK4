#pragma once

#include <iostream>
using namespace std;

class Fraction
{
private:
    int _numerator;
    int _denominator;

public:
    Fraction(int numerator, int denominator);
    Fraction(int numerator);
    Fraction();
    Fraction(const Fraction& other);
    void print()
    {
        cout << _numerator << "/" << _denominator << endl;
    }
};
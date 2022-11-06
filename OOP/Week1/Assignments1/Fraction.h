#pragma once

class Fraction {
private:
    int _numerator;
    int _denominator;

public:
    void Input();
    void Output();
    Fraction Add(Fraction other);
    Fraction Subtract(Fraction other);
    Fraction Multiply(Fraction other);
    Fraction Divide(Fraction other);
    Fraction Reduce();
    int Compare(Fraction other);
    bool isPositive();
    bool isNegative();
    bool isZero();
};

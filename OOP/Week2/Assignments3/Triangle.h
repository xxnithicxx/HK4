#pragma once

#include "Point2D.h"
#include <iostream>
using namespace std;

class Triangle
{
private:
    Point2D _A;
    Point2D _B;
    Point2D _C;

public:
    bool isTriangle(Point2D A, Point2D B, Point2D C);
    Triangle(Point2D A, Point2D B, Point2D C);
    Triangle(Point2D A, Point2D B);
    Triangle(Point2D A);
    Triangle();
    Triangle(const Triangle &other);

    void print()
    {
        cout << "A: ";
        _A.print();
        cout << "B: ";
        _B.print();
        cout << "C: ";
        _C.print();
    }
};


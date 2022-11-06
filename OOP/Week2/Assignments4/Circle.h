#pragma once

#include "Point2D.h"
#include <iostream>
#include <math.h>
using namespace std;

class Circle
{
private:
    Point2D _center;
    double _radius;

public:
    Circle(Point2D center, double radius);
    Circle(Point2D center);
    Circle(double radius);
    Circle();
    Circle(const Circle &other);

    void print()
    {
        cout << "Center: ";
        _center.print();
        cout << "Radius: " << _radius << endl;
    }
};
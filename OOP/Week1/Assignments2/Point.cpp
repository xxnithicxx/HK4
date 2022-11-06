#include "Point.h"
#include <iostream>
#include <math.h>
using namespace std;

void Point::Input()
{
    cout << "Enter x: ";
    cin >> _x;
    cout << "Enter y: ";
    cin >> _y;
}

void Point::Output()
{
    cout << "X: " << _x << endl;
    cout << "Y: " << _y << endl;
}

double Point::Distance(Point other)
{
    float deltax = _x - other._x;
    float deltay = _y - other._y;

    deltax = pow(deltax, 2);
    deltay = pow(deltay, 2);

    float result = sqrt(deltax + deltay);
    return result;
}

int Point::DistanceToOx(){
    return _y;
}

int Point::DistanceToOy(){
    return _x;
}
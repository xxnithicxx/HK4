#pragma once

#include <iostream>
using namespace std;

class Circle
{
private:
    double _radius;

public:
    Circle(double);
    double area();
    double perimeter();
    string toString();
};
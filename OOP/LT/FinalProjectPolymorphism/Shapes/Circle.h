#pragma once

#include <iostream>
#include "IShape.h"
using namespace std;

class Circle : public IShape
{
private:
    int _radius;

public:
    Circle(int);
    double area();
    double perimeter();
    string toString();
};
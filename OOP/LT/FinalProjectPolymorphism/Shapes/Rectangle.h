#pragma once

#include <iostream>
#include "IShape.h"
using namespace std;

class Rectangle: public IShape
{
private:
    int _width;
    int _height;

public:
    Rectangle(int, int);
    double area();
    double perimeter();
    string toString();
};

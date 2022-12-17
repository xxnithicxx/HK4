#pragma once

#include <iostream>
#include "IShape.h"
using namespace std;

class Square : public IShape
{
private:
    int _edge;

public:
    Square(int edge);
    string toString();
    double area();
    double perimeter();
};
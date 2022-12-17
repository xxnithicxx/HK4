#pragma once

#include <iostream>
#include <string>
using namespace std;

class IShape{
public:
    virtual string toString() = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
};
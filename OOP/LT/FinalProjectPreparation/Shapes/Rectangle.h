#pragma once

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int _width;
    int _height;

public:
    Rectangle(int, int);
    int area();
    int perimeter();
    string toString();
};
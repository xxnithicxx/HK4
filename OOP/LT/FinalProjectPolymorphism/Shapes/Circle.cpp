#include "Circle.h"

Circle::Circle(int radius)
{
    this->_radius = radius;
}

double Circle::area()
{
    return 3.14 * this->_radius * this->_radius;
}

double Circle::perimeter()
{
    return 2 * 3.14 * this->_radius;
}

string Circle::toString()
{
    return "Circle";
}
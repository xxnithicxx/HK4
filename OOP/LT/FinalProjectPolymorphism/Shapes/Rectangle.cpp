#include "Rectangle.h"

Rectangle::Rectangle(int width, int height)
{
    this->_width = width;
    this->_height = height;
}

double Rectangle::area()
{
    return this->_width * this->_height;
}

double Rectangle::perimeter()
{
    return 2 * (this->_width + this->_height);
}

string Rectangle::toString()
{
    return "Rectangle";
}
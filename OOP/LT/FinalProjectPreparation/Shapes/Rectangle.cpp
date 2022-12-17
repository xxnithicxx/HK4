#include "Rectangle.h"

Rectangle::Rectangle(int width, int height)
{
    this->_width = width;
    this->_height = height;
}

int Rectangle::area()
{
    return this->_width * this->_height;
}

int Rectangle::perimeter()
{
    return 2 * (this->_width + this->_height);
}

string Rectangle::toString()
{
    return "Rectangle";
}
#include "Square.h"

Square::Square(int edge)
{
    this->_edge = edge;
}

string Square::toString()
{
    return "Square";
}

double Square::area()
{
    double result = this->_edge * this->_edge;
    return result;
}

double Square::perimeter()
{
    double result = this->_edge * 4;
    return result;
}
#include "Square.h"

Square::Square(int edge)
{
    this->_edge = edge;
}

int Square::area()
{
    return this->_edge * this->_edge;
}

int Square::perimeter()
{
    return 4 * this->_edge;
}

string Square::toString()
{
    return "Square";
}
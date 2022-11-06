#include "Point2D.h"

Point2D::Point2D(int x, int y)
{
    _x = x;
    _y = y;
}

Point2D::Point2D(int x)
{
    _x = x;
    _y = 0;
}

Point2D::Point2D()
{
    _x = 0;
    _y = 0;
}

Point2D::Point2D(const Point2D &other)
{
    _x = other._x;
    _y = other._y;
}
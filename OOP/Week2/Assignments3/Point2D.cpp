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

double Point2D::distance(Point2D other)
{
    double result = sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
    return result;
}
#include "Circle.h"

Circle::Circle(Point2D center, double radius)
{
    _center = center;
    _radius = radius;
}

Circle::Circle(Point2D center)
{
    _center = center;
    _radius = 1;
}

Circle::Circle(double radius)
{
    _center = Point2D();
    _radius = radius;
}

Circle::Circle()
{
    _center = Point2D();
    _radius = 1;
}

Circle::Circle(const Circle &other)
{
    _center = other._center;
    _radius = other._radius;
}
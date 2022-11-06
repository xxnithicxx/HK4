#include "Triangle.h"

Triangle::Triangle(Point2D A, Point2D B, Point2D C)
{
    if (isTriangle(A, B, C))
    {
        _A = A;
        _B = B;
        _C = C;
    }
    else
    {
        _A = Point2D(0, 0);
        _B = Point2D(1, 0);
        _C = Point2D(0, 1);
    }
}

Triangle::Triangle(Point2D A, Point2D B)
{
    if (isTriangle(A, B, Point2D(0, 0)))
    {
        _A = A;
        _B = B;
        _C = Point2D(0, 1);
    }
    else
    {
        _A = Point2D(0, 0);
        _B = Point2D(1, 0);
        _C = Point2D(0, 1);
    }
}

Triangle::Triangle(Point2D A)
{
    if (isTriangle(A, Point2D(1, 0), Point2D(0, 1)))
    {
        _A = A;
        _B = Point2D(1, 0);
        _C = Point2D(0, 1);
    }
    else
    {
        _A = Point2D(0, 0);
        _B = Point2D(1, 0);
        _C = Point2D(0, 1);
    }
}

Triangle::Triangle()
{
    _A = Point2D();
    _B = Point2D(1, 0);
    _C = Point2D(0, 1);
}

Triangle::Triangle(const Triangle &other)
{
    _A = other._A;
    _B = other._B;
    _C = other._C;
}

bool Triangle::isTriangle(Point2D A, Point2D B = Point2D(1, 0), Point2D C = Point2D(0, 1))
{
    double AB = A.distance(B);
    double BC = B.distance(C);
    double AC = A.distance(C);

    if (AB + BC > AC && AB + AC > BC && BC + AC > AB)
    {
        return true;
    }
    else
    {
        return false;
    }
}
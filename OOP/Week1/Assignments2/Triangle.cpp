#include "Triangle.h"
#include "math.h"
#include <iostream>
#include <string>
using namespace std;

void Triangle::Input()
{
    cout << "Enter point A: ";
    _a.Input();
    cout << "Enter point B: ";
    _b.Input();
    cout << "Enter point C: ";
    _c.Input();
}

void Triangle::Output()
{
    cout << "First point: " << endl;
    _a.Output();
    cout << "Second point: " << endl;
    _b.Output();
    cout << "Third point: " << endl;
    _c.Output();
}

bool Triangle::isValidTriangle()
{
    double ab = _a.Distance(_b);
    double bc = _b.Distance(_c);
    double ac = _a.Distance(_c);

    if (ab + bc > ac && ab + ac > bc && bc + ac > ab)
        return true;
    else
        return false;
}

string Triangle::Type()
{
    double ab = _a.Distance(_b);
    double bc = _b.Distance(_c);
    double ac = _a.Distance(_c);

    if (ab == bc && bc == ac)
        return "Equilateral";
    else if (ab == bc || bc == ac || ac == ab)
        return "Isosceles";
    else if (ab * ab + bc * bc == ac * ac || ab * ab + ac * ac == bc * bc || bc * bc + ac * ac == ab * ab)
        return "Right-angled";
    else
        return "Scalene";
}

double Triangle::Perimeter()
{
    double ab = _a.Distance(_b);
    double bc = _b.Distance(_c);
    double ac = _a.Distance(_c);

    return ab + bc + ac;
}

double Triangle::Area()
{
    double ab = _a.Distance(_b);
    double bc = _b.Distance(_c);
    double ac = _a.Distance(_c);

    double semi = (ab + bc + ac) / 2;
    double result = sqrt(semi * (semi - ab) * (semi - bc) * (semi - ac));
    return result;
}

Point Triangle::Center(){
    Point result;

    result.setY((_a.DistanceToOx() + _b.DistanceToOx() + _c.DistanceToOx()) / 3);
    result.setX((_a.DistanceToOy() + _b.DistanceToOy() + _c.DistanceToOy()) / 3);

    return result;
}

#pragma once
#include "Point.h"
#include <string>

class Triangle {
private:
    Point _a;
    Point _b;
    Point _c;

public:
    void Input();
    void Output();
    bool isValidTriangle();
    std::string Type();
    double Perimeter();
    double Area();
    Point Center();
};
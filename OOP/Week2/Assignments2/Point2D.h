#pragma once

#include <iostream>
using namespace std;

class Point2D
{
private:
    int _x;
    int _y;

public:
    Point2D(int x, int y);
    Point2D(int x);
    Point2D();
    Point2D(const Point2D &other);
    void print()
    {
        cout << "(" << _x << ", " << _y << ")" << endl;
    }
};
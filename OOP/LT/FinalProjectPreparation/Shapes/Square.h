#pragma once

#include <iostream>
using namespace std;

class Square
{
private:
    int _edge;

public:
    Square(int);
    int area();
    int perimeter();
    string toString();
};
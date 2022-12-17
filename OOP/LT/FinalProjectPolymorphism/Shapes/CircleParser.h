#pragma once

#include <iostream>
#include "IParsable.h"
#include "Utils.h"
#include "Circle.h"
using namespace std;

class CircleParser : public IParsable
{
    IShape *parse(string str)
    {
        string argv = Utils::String::split(str, "=")[1];
        return new Circle(stoi(argv));
    }
};

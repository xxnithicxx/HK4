#pragma once

#include <iostream>
#include <vector>
#include "Utils.h"
#include "IParsable.h"
#include "Rectangle.h"
using namespace std;

class RectangleParser : public IParsable
{
    IShape *parse(string str)
    {
        vector<string> tokens = Utils::String::split(str, ", ");
        string argv1 = Utils::String::split(tokens[0], "=")[1];
        string argv2 = Utils::String::split(tokens[1], "=")[1];
        return new Rectangle(stoi(argv1), stoi(argv2));
    }
};

#pragma once

#include <iostream>
#include "IParsable.h"
#include "Utils.h"
#include "Square.h"
using namespace std;

class SquareParser: public IParsable
{
    IShape* parse(string str){
        string argv = Utils::String::split(str, "=")[1];
        return new Square(stoi(argv));
    }
};

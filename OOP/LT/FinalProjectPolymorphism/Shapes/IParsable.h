#pragma once

#include <iostream>
#include "IShape.h"
using namespace std;

class IParsable
{
public:
    virtual IShape* parse(string str) = 0;
};
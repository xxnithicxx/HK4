#pragma once

#include <iostream>
using namespace std;

class IValueConverter
{
public:
    virtual string toString() = 0;
};
#pragma once

#include <iostream>
#include "Employee.h"
using namespace std;

class IParsable
{
public:
    virtual Employee* parse(string data) = 0;
    virtual string getType() = 0;
};
#pragma once

#include <iostream>
using namespace std;

class Employee
{
public:
    virtual int salary() = 0;
    virtual string toString() = 0;
};
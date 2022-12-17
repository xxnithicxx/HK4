#pragma once

#include <iostream>
using namespace std;

class Manager
{
private:
    int _employees;
    int _payRate;

public:
    Manager(int, int);
    int salary();
};
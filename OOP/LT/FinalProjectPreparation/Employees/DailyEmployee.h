#pragma once

#include <iostream>
using namespace std;

class DailyEmployee
{
    int _days;
    int _payRate;

public:
    DailyEmployee(int, int);
    int salary();
};

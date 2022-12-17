#pragma once

#include <iostream>
#include "Employee.h"
using namespace std;

class DailyEmployee : public Employee
{
private:
    int _dayCount;
    int _paymentPerDay;

public:
    DailyEmployee(int dayCount, int paymentPerDay)
    {
        _dayCount = dayCount;
        _paymentPerDay = paymentPerDay;
    }

    int salary()
    {
        return _dayCount * _paymentPerDay;
    }

    string toString()
    {
        return "DailyEmployee";
    }
};
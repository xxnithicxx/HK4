#pragma once

#include <iostream>
#include "Employee.h"
using namespace std;

class Manager : public Employee
{
private:
    int _employeeCount;
    int _paymentPerEmployee;
    int _baseSalary;

public:
    Manager(int employeeCount, int paymentPerEmployee, int baseSalary)
    {
        _employeeCount = employeeCount;
        _paymentPerEmployee = paymentPerEmployee;
        _baseSalary = baseSalary;
    }

    int salary()
    {
        return (_employeeCount * _paymentPerEmployee) + _baseSalary;
    }

    string toString()
    {
        return "Manager";
    }
};

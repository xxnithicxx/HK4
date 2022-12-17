#pragma once

#include <string>
#include <iostream>
#include "Employee.h"
using namespace std;

class OfficeEmployee : public Employee
{
private:
    int _workDays;

public:
    OfficeEmployee();
    OfficeEmployee(string id, string name, string hireDate, string address, int workDays);
    OfficeEmployee(string id, string name, string hireDate, string address);
    OfficeEmployee(string id, string name, string hireDate);
    OfficeEmployee(string id, string name);
    OfficeEmployee(string id);

    void input();
    void output();
    int getSalary();
};
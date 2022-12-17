#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Employee.h"
#include "Worker.h"
#include "OfficeEmployee.h"
using namespace std;

class Company
{
private:
    vector<Employee*> _employees;

public:
    Company();
    ~Company();

    void addEmployee(Employee* employee);
    void input();
    void output();
    void getTotalSalary();
    void getHighestSalary();
};
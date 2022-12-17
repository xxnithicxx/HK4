#pragma once

#include <string>
#include <iostream>
#include "Employee.h"
using namespace std;

class Worker : public Employee
{
private:
    int _items;

public:
    Worker();
    Worker(string id, string name, string hireDate, string address, int items);
    Worker(string id, string name, string hireDate, string address);
    Worker(string id, string name, string hireDate);
    Worker(string id, string name);
    Worker(string id);

    void input();
    void output();
    int getSalary();
};

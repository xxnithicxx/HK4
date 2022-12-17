#pragma once

#include <string>
#include <iostream>
using namespace std;

class Employee
{
protected:
    string _id;
    string _name;
    string _hireDate;
    string _address;

public:
    Employee();
    Employee(string id, string name, string hireDate, string address);
    Employee(string id, string name, string hireDate);
    Employee(string id, string name);
    Employee(string id);


    virtual void input();
    virtual void output();
    virtual int getSalary() = 0;
};
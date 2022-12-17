#include "Employee.h"

Employee::Employee()
{
    _id = "";
    _name = "";
    _hireDate = "";
    _address = "";
}

Employee::Employee(string id, string name, string hireDate, string address)
{
    _id = id;
    _name = name;
    _hireDate = hireDate;
    _address = address;
}

Employee::Employee(string id, string name, string hireDate)
{
    _id = id;
    _name = name;
    _hireDate = hireDate;
    _address = "";
}

Employee::Employee(string id, string name)
{
    _id = id;
    _name = name;
    _hireDate = "";
    _address = "";
}

Employee::Employee(string id)
{
    _id = id;
    _name = "";
    _hireDate = "";
    _address = "";
}

void Employee::input()
{
    cout << "Enter ID: ";
    getline(cin, _id);
    cout << "Enter name: ";
    getline(cin, _name);
    cout << "Enter hire date: ";
    getline(cin, _hireDate);
    cout << "Enter address: ";
    getline(cin, _address);
}

void Employee::output()
{
    cout << "ID: " << _id << endl;
    cout << "Name: " << _name << endl;
    cout << "Hire date: " << _hireDate << endl;
    cout << "Address: " << _address << endl;
}
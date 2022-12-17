#include "OfficeEmployee.h"

OfficeEmployee::OfficeEmployee(): Employee()
{
    _workDays = 0;
}

OfficeEmployee::OfficeEmployee(string id, string name, string hireDate, string address, int workDays): Employee(id, name, hireDate, address)
{
    _workDays = workDays;
}

OfficeEmployee::OfficeEmployee(string id, string name, string hireDate, string address): Employee(id, name, hireDate, address)
{
    _workDays = 0;
}

OfficeEmployee::OfficeEmployee(string id, string name, string hireDate): Employee(id, name, hireDate)
{
    _workDays = 0;
}

OfficeEmployee::OfficeEmployee(string id, string name): Employee(id, name)
{
    _workDays = 0;
}

OfficeEmployee::OfficeEmployee(string id): Employee(id)
{
    _workDays = 0;
}

void OfficeEmployee::input()
{
    Employee::input();
    cout << "Enter number of work days: ";
    cin >> _workDays;
}

void OfficeEmployee::output()
{
    Employee::output();
    cout << "Number of work days: " << _workDays << endl;
}

int OfficeEmployee::getSalary()
{
    return _workDays * 300;
}

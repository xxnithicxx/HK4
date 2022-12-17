#include "Company.h"

Company::Company()
{
}

Company::~Company()
{
    for (auto employee : _employees)
    {
        delete employee;
    }
}

void Company::addEmployee(Employee* employee)
{
    _employees.push_back(employee);
}

void Company::input()
{
    int choice;
    do
    {
        cout << "1. Worker" << endl;
        cout << "2. Office Employee" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            Worker* worker = new Worker();
            worker->input();
            addEmployee(worker);
            break;
        }
        case 2:
        {
            OfficeEmployee* officeEmployee = new OfficeEmployee();
            officeEmployee->input();
            addEmployee(officeEmployee);
            break;
        }
        case 3:
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 3);
}

void Company::output()
{
    for (auto employee : _employees)
    {
        employee->output();
        cout << "---------------------------------" << endl;
    }
}

void Company::getTotalSalary()
{
    int totalSalary = 0;
    for (auto employee : _employees)
    {
        totalSalary += employee->getSalary();
    }
    cout << "Total salary: " << totalSalary << endl;
}

void Company::getHighestSalary()
{
    int highestSalary = 0;
    for (auto employee : _employees)
    {
        if (employee->getSalary() > highestSalary)
        {
            highestSalary = employee->getSalary();
        }
    }

    cout << "Highest salary: " << highestSalary << endl;
    cout << "List of employees with highest salary: " << endl;

    for (auto employee : _employees)
    {
        if (employee->getSalary() == highestSalary)
        {
            employee->output();
        }
    }
}
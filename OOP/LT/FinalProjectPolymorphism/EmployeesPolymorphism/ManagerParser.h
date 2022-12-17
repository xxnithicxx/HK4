#pragma once

#include <iostream>
#include "IParsable.h"
#include "Manager.h"
using namespace std;

class ManagerParser : public IParsable
{
public:
    Employee* parse(string data)
    {
        int employeeCount = 0;
        int paymentPerEmployee = 0;
        int baseSalary = 0;

        int splitPosition = data.find_first_of("=");
        string key = data.substr(0, splitPosition);
        string value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        employeeCount = stoi(value);

        data = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        splitPosition = data.find_first_of("=");
        key = data.substr(0, splitPosition);
        value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        paymentPerEmployee = stoi(value);

        data = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        splitPosition = data.find_first_of("=");
        key = data.substr(0, splitPosition);
        value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        baseSalary = stoi(value);

        return new Manager(employeeCount, paymentPerEmployee, baseSalary);
    }

    string getType()
    {
        return "Manager";
    }
};
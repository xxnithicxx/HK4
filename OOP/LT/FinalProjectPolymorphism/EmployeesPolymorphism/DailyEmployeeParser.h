#pragma once

#include <iostream>
#include "IParsable.h"
#include "DailyEmployee.h"
using namespace std;

class DailyEmployeeParser : public IParsable
{
public:
    Employee* parse(string data)
    {
        int dayCount = 0;
        int paymentPerDay = 0;

        int splitPosition = data.find_first_of("=");
        string key = data.substr(0, splitPosition);
        string value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        dayCount = stoi(value);

        data = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        splitPosition = data.find_first_of("=");
        key = data.substr(0, splitPosition);
        value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        paymentPerDay = stoi(value);

        return new DailyEmployee(dayCount, paymentPerDay);
    }

    string getType()
    {
        return "DailyEmployee";
    }
};

#pragma once

#include <iostream>
#include "IParsable.h"
#include "ProductEmployee.h"
using namespace std;

class ProductEmployeeParser : public IParsable
{
public:
    Employee* parse(string data)
    {
        int productCount = 0;
        int paymentPerProduct = 0;

        int splitPosition = data.find_first_of("=");
        string key = data.substr(0, splitPosition);
        string value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        productCount = stoi(value);

        data = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        splitPosition = data.find_first_of("=");
        key = data.substr(0, splitPosition);
        value = data.substr(splitPosition + 1, data.length() - splitPosition - 1);
        paymentPerProduct = stoi(value);

        return new ProductEmployee(productCount, paymentPerProduct);
    }

    string getType()
    {
        return "ProductEmployee";
    }
};
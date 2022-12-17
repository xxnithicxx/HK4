#pragma once

#include <iostream>
#include "Employee.h"
using namespace std;

class ProductEmployee : public Employee
{
private:
    int _productCount;
    int _paymentPerProduct;

public:
    ProductEmployee(int productCount, int paymentPerProduct)
    {
        _productCount = productCount;
        _paymentPerProduct = paymentPerProduct;
    }

    int salary()
    {
        return _productCount * _paymentPerProduct;
    }

    string toString()
    {
        return "ProductEmployee";
    }
};
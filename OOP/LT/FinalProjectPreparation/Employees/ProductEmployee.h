#pragma once

#include <iostream>
using namespace std;

class ProductEmployee
{
private:
    int _products;
    int _payRate;

public:
    ProductEmployee(int, int);
    int salary();
};
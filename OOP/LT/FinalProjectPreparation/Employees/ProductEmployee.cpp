#include "ProductEmployee.h"

ProductEmployee::ProductEmployee(int products, int payRate)
{
    this->_products = products;
    this->_payRate = payRate;
}

int ProductEmployee::salary()
{
    int payment = _products * _payRate;
    return payment;
}
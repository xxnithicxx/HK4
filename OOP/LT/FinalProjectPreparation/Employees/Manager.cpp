#include "Manager.h"

Manager::Manager(int employees, int payRate)
{
    this->_employees = employees;
    this->_payRate = payRate;
}

int Manager::salary(){
    int payment = _employees * 500000 + _payRate;
    return payment;
}
#include "DailyEmployee.h"

DailyEmployee::DailyEmployee(int days, int payRate)
{
    this->_days = days;
    this->_payRate = payRate;
}

int DailyEmployee::salary(){
    int payment = _days * _payRate;
    return payment;
}
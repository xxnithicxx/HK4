#include "MyDate.h"

bool checkDay(int day)
{
    if (day >= 1 && day <= 31)
        return true;
    return false;
}

bool checkMonth(int month)
{
    if (month >= 1 && month <= 12)
        return true;
    return false;
}

bool checkYear(int year)
{
    if (year >= 0 || year <= 9999)
        return true;
    return false;
}

bool checkDate(int day, int month, int year)
{
    if (!checkDay(day) && !checkMonth(month) && !checkYear(year))
        return false;

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        if (month == 2 && day > 29)
            return false;
    }
    else
    {
        if (month == 2 && day > 28)
            return false;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
            return false;
    }

    return true;
}

MyDate::MyDate(int day, int month, int year){
    if (checkDate(day, month, year))
    {
        _day = day;
        _month = month;
        _year = year;
    }
    else
    {
        _day = 1;
        _month = 1;
        _year = 1;
    }
}

MyDate::MyDate(int day, int month){
    if (checkDate(day, month, 1))
    {
        _day = day;
        _month = month;
        _year = 1;
    }
    else
    {
        _day = 1;
        _month = 1;
        _year = 1;
    }
}

MyDate::MyDate(int day){
    if (checkDate(day, 1, 1))
    {
        _day = day;
        _month = 1;
        _year = 1;
    }
    else
    {
        _day = 1;
        _month = 1;
        _year = 1;
    }
}

MyDate::MyDate(){
    _day = 1;
    _month = 1;
    _year = 1;
}

MyDate::MyDate(const MyDate &other){
    _day = other._day;
    _month = other._month;
    _year = other._year;
}
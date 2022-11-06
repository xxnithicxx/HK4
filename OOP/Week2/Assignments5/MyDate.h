#pragma once

#include <iostream>
using namespace std;

class MyDate
{
private:
    int _day;
    int _month;
    int _year;

public:
    MyDate(int day, int month, int year);
    MyDate(int day, int month);
    MyDate(int day);
    MyDate();
    MyDate(const MyDate &other);

    bool checkDay(int day);
    bool checkMonth(int month);
    bool checkYear(int year);
    bool checkDate(int day, int month, int year);

    void print()
    {
        cout << _day << "/" << _month << "/" << _year << endl;
    }
};
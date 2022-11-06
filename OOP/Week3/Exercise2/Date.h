#pragma once

#include "math.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

extern vector<int> monthDays;

class Date
{
private:
    int _day;
    int _month;
    int _year;

public:
    Date();
    Date(int year);
    Date(int year, int month);
    Date(int year, int month, int day);
    Date(const Date &other);

    Date &operator=(const Date &other);
    Date operator+(const int &num);
    Date operator-(const int &num);
    Date &operator+=(const int &num);
    Date &operator-=(const int &num);
    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);
    bool operator==(const Date &other);
    bool operator!=(const Date &other);
    bool operator>=(const Date &other);
    bool operator<=(const Date &other);
    bool operator>(const Date &other);
    bool operator<(const Date &other);
    friend ostream &operator<<(ostream &os, const Date &date);
    friend istream &operator>>(istream &is, Date &date);
    operator int() const;
    operator long() const;

    bool checkDate(int day, int month, int year);
    bool isLeapYear(int year) const;
    Date Tomorrow();
    Date Yesterday();
    void print();
    int countLeapYearDays(Date d) const;
};
#pragma once

#include <iostream>
using namespace std;

class MyTime
{
private:
    int _hour;
    int _minute;
    int _second;

public:
    MyTime(int hour, int minute, int second);
    MyTime(int hour, int minute);
    MyTime(int hour);
    MyTime();
    MyTime(const MyTime &other);

    void print()
    {
        cout << _hour << ":" << _minute << ":" << _second << endl;
    }

    bool isTime(int hour = 0, int minute = 0, int second = 0)
    {
        if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#include "MyTime.h"

MyTime::MyTime(int hour, int minute, int second)
{
    if (isTime(hour, minute, second))
    {
        _hour = hour;
        _minute = minute;
        _second = second;
    }
    else
    {
        _hour = 0;
        _minute = 0;
        _second = 0;
    }
}

MyTime::MyTime(int hour, int minute)
{
    if (isTime(hour, minute))
    {
        _hour = hour;
        _minute = minute;
        _second = 0;
    }
    else
    {
        _hour = 0;
        _minute = 0;
        _second = 0;
    }
}

MyTime::MyTime(int hour)
{
    if (isTime(hour))
    {
        _hour = hour;
        _minute = 0;
        _second = 0;
    }
    else
    {
        _hour = 0;
        _minute = 0;
        _second = 0;
    }
}

MyTime::MyTime()
{
    _hour = 0;
    _minute = 0;
    _second = 0;
}

MyTime::MyTime(const MyTime &other)
{
    _hour = other._hour;
    _minute = other._minute;
    _second = other._second;
}
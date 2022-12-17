#include "NgayThang.h"

NgayThang::NgayThang(int year, int month, int day)
{
    _year = abs(year);
    _month = abs(month);
    _day = abs(day);

    convertToDate();

    if (*this > _ngayThang)
    {
        _ngayThang = *this;
    }
}

NgayThang::NgayThang(int month, int day)
{
    _year = 0;
    _month = abs(month);
    _day = abs(day);

    convertToDate();

    if (*this > _ngayThang)
    {
        _ngayThang = *this;
    }
}

NgayThang::NgayThang(int day)
{
    _year = 0;
    _month = 0;
    _day = abs(day);

    convertToDate();

    if (*this > _ngayThang)
    {
        _ngayThang = *this;
    }
}

NgayThang::NgayThang()
{
    _year = 1;
    _month = 1;
    _day = 1;
}

void NgayThang::convertToDate()
{
    int count = 0;

    while (_day > 30)
    {
        _day -= 30;
        count++;
    }

    _month += count;
    count = 0;

    while (_month > 12)
    {
        _month -= 12;
        count++;
    }

    _year += count;
}

ostream &operator<<(ostream &os, const NgayThang &nt)
{
    os << nt._day << "/" << nt._month << "/" << nt._year;
    return os;
}

NgayThang NgayThang::operator+(const NgayThang &nt)
{
    NgayThang temp;
    temp._day = _day + nt._day;
    temp._month = _month + nt._month;
    temp._year = _year + nt._year;

    temp.convertToDate();

    if (temp > _ngayThang)
    {
        _ngayThang = temp;
    }

    return temp;
}

NgayThang NgayThang::operator+(int day)
{
    NgayThang temp;
    temp._day = _day + day;
    temp._month = _month;
    temp._year = _year;

    temp.convertToDate();

    if (temp > _ngayThang)
    {
        _ngayThang = temp;
    }

    return temp;
}

NgayThang operator+(int day, const NgayThang &nt)
{
    NgayThang temp;
    temp._day = nt._day + day;
    temp._month = nt._month;
    temp._year = nt._year;

    temp.convertToDate();

    if (temp > _ngayThang)
    {
        _ngayThang = temp;
    }

    return temp;
}

NgayThang &NgayThang::operator++()
{
    _day++;
    convertToDate();

    if (*this > _ngayThang)
    {
        _ngayThang = *this;
    }

    return *this;
}

NgayThang NgayThang::operator++(int)
{
    NgayThang temp = *this;
    _day++;
    convertToDate();

    if (*this > _ngayThang)
    {
        _ngayThang = *this;
    }

    return temp;
}

bool NgayThang::operator>(const NgayThang &nt)
{
    if (_year > nt._year)
        return true;
    else if (_year == nt._year)
    {
        if (_month > nt._month)
            return true;
        else if (_month == nt._month)
        {
            if (_day > nt._day)
                return true;
        }
    }

    return false;
}

NgayThang *NgayThang::NgayThangLonNhat()
{
    return &_ngayThang;
}
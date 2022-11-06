#include "Date.h"

vector<int> monthDays = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

Date::Date()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    _day = ltm->tm_mday;
    _month = 1 + ltm->tm_mon;
    _year = 1900 + ltm->tm_year;
}

Date::Date(int year)
{
    _day = 1;
    _month = 1;
    _year = year;
}

Date::Date(int year, int month)
{
    _day = 1;
    _month = month;
    _year = year;
}

Date::Date(int year, int month, int day)
{
    _day = day;
    _month = month;
    _year = year;
}

Date::Date(const Date &other)
{
    _day = other._day;
    _month = other._month;
    _year = other._year;
}

Date &Date::operator=(const Date &other)
{
    _day = other._day;
    _month = other._month;
    _year = other._year;
    return *this;
}

bool Date::checkDate(int day, int month, int year)
{
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
        return false;
    if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2 && day == 29 && !isLeapYear(year))
        return false;
    return true;
}

bool Date::isLeapYear(int year) const
{
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    if (year % 400 == 0)
        return true;
    return false;
}

Date Date::Tomorrow()
{
    Date temp;
    temp._day = _day + 1;
    temp._month = _month;
    temp._year = _year;
    if (!checkDate(temp._day, temp._month, temp._year))
    {
        temp._day = 1;
        temp._month++;
        if (!checkDate(temp._day, temp._month, temp._year))
        {
            temp._month = 1;
            temp._year++;
        }
    }
    return temp;
}

Date Date::Yesterday()
{
    Date temp;
    temp._day = _day - 1;
    temp._month = _month;
    temp._year = _year;
    if (!checkDate(temp._day, temp._month, temp._year))
    {
        temp._month--;
        if (!checkDate(temp._day, temp._month, temp._year))
        {
            temp._month = 12;
            temp._year--;
        }
        switch (temp._month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            temp._day = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            temp._day = 30;
            break;
        case 2:
            if (isLeapYear(temp._year))
                temp._day = 29;
            else
                temp._day = 28;
            break;
        }
    }
    return temp;
}

Date Date::operator+(const int &days)
{
    for (int i = 0; i < days; i++)
        *this = Tomorrow();
    return *this;
}

Date Date::operator-(const int &days)
{
    for (int i = 0; i < days; i++)
        *this = Yesterday();
    return *this;
}

Date &Date::operator+=(const int &days)
{
    for (int i = 0; i < days; i++)
        *this = Tomorrow();
    return *this;
}

Date &Date::operator-=(const int &days)
{
    for (int i = 0; i < days; i++)
        *this = Yesterday();
    return *this;
}

Date &Date::operator++()
{
    *this = Tomorrow();
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    *this = Tomorrow();
    return temp;
}

Date &Date::operator--()
{
    *this = Yesterday();
    return *this;
}

Date Date::operator--(int)
{
    Date temp = *this;
    *this = Yesterday();
    return temp;
}

bool Date::operator==(const Date &other)
{
    return _day == other._day && _month == other._month && _year == other._year;
}

bool Date::operator!=(const Date &other)
{
    return _day != other._day || _month != other._month || _year != other._year;
}

bool Date::operator<(const Date &other)
{
    if (_year < other._year)
        return true;
    if (_year == other._year && _month < other._month)
        return true;
    if (_year == other._year && _month == other._month && _day < other._day)
        return true;
    return false;
}

bool Date::operator>(const Date &other)
{
    if (_year > other._year)
        return true;
    if (_year == other._year && _month > other._month)
        return true;
    if (_year == other._year && _month == other._month && _day > other._day)
        return true;
    return false;
}

bool Date::operator<=(const Date &other)
{
    if (_year < other._year)
        return true;
    if (_year == other._year && _month < other._month)
        return true;
    if (_year == other._year && _month == other._month && _day < other._day)
        return true;
    if (_year == other._year && _month == other._month && _day == other._day)
        return true;
    return false;
}

bool Date::operator>=(const Date &other)
{
    if (_year > other._year)
        return true;
    if (_year == other._year && _month > other._month)
        return true;
    if (_year == other._year && _month == other._month && _day > other._day)
        return true;
    if (_year == other._year && _month == other._month && _day == other._day)
        return true;
    return false;
}

ostream &operator<<(ostream &out, const Date &date)
{
    out << date._day << "/" << date._month << "/" << date._year;
    return out;
}

istream &operator>>(istream &in, Date &date)
{
    in >> date._day >> date._month >> date._year;
    return in;
}

int Date::countLeapYearDays(Date d) const
{
    int years = d._year;
    if (d._month <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

Date::operator int() const
{
    Date pivot;
    pivot._day = 1;
    pivot._month = 1;

    // Calculate days from pivot to 1/1/0000
    int dayCnt1 = (pivot._year * 365);
    dayCnt1 += monthDays[pivot._month - 1];
    dayCnt1 += pivot._day;
    dayCnt1 += countLeapYearDays(pivot);

    // Calculate days from pivot to 1/1/0000
    int dayCnt2 = (_year * 365);
    dayCnt2 += monthDays[_month - 1];
    dayCnt2 += _day;
    dayCnt2 += countLeapYearDays(*this);

    // Difference between two dates
    return abs(dayCnt2 - dayCnt1);
}

Date::operator long() const
{
    Date pivot(1, 1, 1);

    // Calculate days from pivot to 1/1/0000
    int dayCnt1 = (pivot._year * 365);
    dayCnt1 += monthDays[pivot._month - 1];
    dayCnt1 += pivot._day;
    dayCnt1 += countLeapYearDays(pivot);

    // Calculate days from pivot to 1/1/0000
    int dayCnt2 = (_year * 365);
    dayCnt2 += monthDays[_month - 1];
    dayCnt2 += _day;
    dayCnt2 += countLeapYearDays(*this);

    // Difference between two dates
    return abs(dayCnt2 - dayCnt1);
}
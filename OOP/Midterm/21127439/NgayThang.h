#pragma once

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class NgayThang
{
private:
    int _day;
    int _month;
    int _year;

public:
    NgayThang(int year, int month, int day);
    NgayThang(int month, int day);
    NgayThang(int day);
    NgayThang();

    friend ostream &operator<<(ostream &os, const NgayThang &nt);

    NgayThang operator+(const NgayThang &nt);
    NgayThang operator+(int day);
    friend NgayThang operator+(int day, const NgayThang &nt);
    NgayThang &operator++();
    NgayThang operator++(int);
    bool operator>(const NgayThang &nt);

    static NgayThang *NgayThangLonNhat();
    void convertToDate();
};

static NgayThang _ngayThang;
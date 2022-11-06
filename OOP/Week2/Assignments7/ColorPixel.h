#pragma once

#include <iostream>
#include <string>
using namespace std;

class ColorPixel
{
private:
    int _red;
    int _green;
    int _blue;

public:
    ColorPixel(int red, int green, int blue);
    ColorPixel(int red, int green);
    ColorPixel(int red);
    ColorPixel();
    ColorPixel(const ColorPixel &other);

    void print() const
    {
        cout << "Red: " << _red << ", Green: " << _green << ", Blue: " << _blue << endl;
        cout << "Hex: " << hex << _red << " " << _green << " " << _blue << endl;
    }
};
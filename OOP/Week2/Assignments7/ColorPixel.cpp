#include "ColorPixel.h"

ColorPixel::ColorPixel(int red, int green, int blue)
{
    if (red < 0 && red > 255)
        red = 0;
    if (green < 0 && green > 255)
        green = 0;
    if (blue < 0 && blue > 255)
        blue = 0;

    _red = red;
    _green = green;
    _blue = blue;
}

ColorPixel::ColorPixel(int red, int green)
{
    if (red < 0 && red > 255)
        red = 0;
    if (green < 0 && green > 255)
        green = 0;

    _red = red;
    _green = green;
    _blue = 0;
}

ColorPixel::ColorPixel(int red)
{
    if (red < 0 && red > 255)
        red = 0;

    _red = red;
    _green = 0;
    _blue = 0;
}

ColorPixel::ColorPixel()
{
    _red = 0;
    _green = 0;
    _blue = 0;
}

ColorPixel::ColorPixel(const ColorPixel &other)
{
    _red = other._red;
    _green = other._green;
    _blue = other._blue;
}
#include "Rectangle.h"

Rectangle::Rectangle(float w, float h)
{
  width = w;
  height = h;
}

float Rectangle::Area()
{
  return width * height;
}

void Rectangle::Input(istream& inDevice)
{
  inDevice >> width >> height;
}
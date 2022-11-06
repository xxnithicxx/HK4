#include"Circle.h"

Circle:: Circle(float r): Ellipse(r,r){}

void Circle:: Input(istream& inDevice)
{
  inDevice >> Ra;
  Rb = Ra;
}
#include"Ellipse.h"

Ellipse:: Ellipse(float a, float b)
{
  Ra =a;
  Rb =b;
}
void Ellipse:: Input(istream& inDevice)
{
  inDevice >> Ra >> Rb;
}
float Ellipse:: Area ()
{
  return PI * Ra*Rb;
}
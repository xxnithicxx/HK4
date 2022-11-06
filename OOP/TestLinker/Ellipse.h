#ifndef _Ellipse_h
#define _Ellipse_h
#define PI (float)3.1415
#include "Figure.h"

class Ellipse: public Figure{
  protected:
  float Ra, Rb;
  public:
    Ellipse(float a, float b);
    virtual float Area();
    virtual void Input(istream& inDevice);
};

#endif
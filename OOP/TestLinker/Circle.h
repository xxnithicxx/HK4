
#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "Ellipse.h"

class Circle: public Ellipse{
  public:
    Circle(float r = 0);
    virtual void Input(istream& inDevice);
};

#endif
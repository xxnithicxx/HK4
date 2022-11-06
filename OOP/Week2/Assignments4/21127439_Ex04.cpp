#include "Circle.h"

int main()
{
    Circle c1;
    Circle c2(Point2D(1, 2), 3);
    Circle c3(Point2D(1, 2));
    Circle c4(3);
    Circle c5(c2);

    c1.print();
    c2.print();
    c3.print();
    c4.print();
    c5.print();

    return 0;
}
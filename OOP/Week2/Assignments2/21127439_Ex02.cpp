#include "Point2D.h"

int main()
{
    Point2D p1(1, 2);
    Point2D p2(1);
    Point2D p3;
    Point2D p4(p1);

    p1.print();
    p2.print();
    p3.print();
    p4.print();

    return 0;
}
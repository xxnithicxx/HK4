#include "Triangle.h"

int main()
{
    Triangle t1;
    Triangle t2(1, 2, 3);
    Triangle t3(1, 2);
    Triangle t4(1);
    Triangle t5(t2);

    t1.print();
    t2.print();
    t3.print();
    t4.print();
    t5.print();

    return 0;
}
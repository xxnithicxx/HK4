#include "MyTime.h"

int main()
{
    MyTime t1(1, 2, 3);
    MyTime t2(1, 2);
    MyTime t3(1);
    MyTime t4;
    MyTime t5(t1);

    t1.print();
    t2.print();
    t3.print();
    t4.print();
    t5.print();

    return 0;
}
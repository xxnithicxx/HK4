#include "MyDate.h"

int main()
{
    MyDate d1;
    MyDate d2(1, 2, 3);
    MyDate d3(1, 2);
    MyDate d4(1);
    MyDate d5(d2);

    d1.print();
    d2.print();
    d3.print();
    d4.print();
    d5.print();

    return 0;
}
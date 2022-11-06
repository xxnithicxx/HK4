#include "Fraction.h"

int main()
{
    Fraction f1(1, 2);
    Fraction f2(1);
    Fraction f3;
    Fraction f4(f2);

    f1.print();
    f2.print();
    f3.print();
    f4.print();

    return 0;
}
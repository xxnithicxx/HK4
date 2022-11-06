#include "Student.h"

int main()
{
    Student s1(1, "Nguyen Van A", "TPHCM", 3.5);
    Student s2(2, "Nguyen Van B", "TPHCM");
    Student s3(3, "Nguyen Van C");
    Student s4(4);
    Student s5;

    s1.print();
    s2.print();
    s3.print();
    s4.print();
    s5.print();

    return 0;
}
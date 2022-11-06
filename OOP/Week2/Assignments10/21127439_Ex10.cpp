#include "Lecturer.h"

int main(){
    Lecturer l1(1, "Nguyen Van A", "PhD", 5);
    Lecturer l2(2, "Nguyen Van B", "PhD");
    Lecturer l3(3, "Nguyen Van C");
    Lecturer l4(4);
    Lecturer l5;

    l1.print();
    l2.print();
    l3.print();
    l4.print();
    l5.print();

    return 0;
}
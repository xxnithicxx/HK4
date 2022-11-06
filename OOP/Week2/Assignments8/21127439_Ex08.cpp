#include "MyIntArray.h"

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    MyIntArray a1(arr, 5);
    MyIntArray a2(argc, argv);
    MyIntArray a3(5);
    MyIntArray a4;
    MyIntArray a5(a1);
    
    a1.print();
    a2.print();
    a3.print();
    a4.print();
    a5.print();

    return 0;
}
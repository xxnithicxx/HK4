#include "ColorPixel.h"

int main(){
    ColorPixel c1(100, 200, 150);
    ColorPixel c2(1, 2);
    ColorPixel c3(1);
    ColorPixel c4;
    ColorPixel c5(c1);

    c1.print();
    c2.print();
    c3.print();
    c4.print();
    c5.print();

    return 0;
}
#include "ABCFarm.h"

int main()
{
    DairyCow cow1(150, 3);
    DairyCow cow2;
    cow2.setWeight(200);
    cow2.setAge(-10);
    cow2 = cow1;

    cout << "Cow 1: " << cow1.toString() << endl;
    cout << "Cow 2: " << cow2.toString() << endl;

    Goat goat1(50, 2);
    Goat goat2;
    goat2.setWeight(100);
    goat2.setAge(-5);

    cout << "Goat 1: " << goat1.toString() << endl;
    cout << "Goat 2: " << goat2.toString() << endl;

    ABCFarm farm;
    farm.Input();
    farm.Output();
    farm.OutputByAge(1, 5);
    
    return 0;
}
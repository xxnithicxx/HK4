#pragma once

#include <vector>
#include "Goat.h"
#include "DairyCow.h"

class ABCFarm
{
private:
    vector<DairyCow> cows;
    vector<Goat> goats;

public:
    void Input();
    void Output();
    void OutputByAge(int min, int max);
};
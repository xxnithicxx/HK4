#pragma once

#include <iostream>
#include <string>
#include "Animal.h"
#include "ID.h"
using namespace std;

class DairyCow : public Animal
{
public:
    DairyCow(int weight, int age);
    DairyCow();
    DairyCow(const DairyCow &cow);

    DairyCow &operator=(const DairyCow &other);

    string toString() const;
};

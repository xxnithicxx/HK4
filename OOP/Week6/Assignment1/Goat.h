#pragma once

#include <iostream>
#include <string>
#include "Animal.h"
#include "ID.h"
using namespace std;

class Goat : public Animal
{
public:
    Goat(int weight, int age);
    Goat();
    Goat(const Goat &goat);

    Goat &operator=(const Goat &other);

    string toString() const;
};
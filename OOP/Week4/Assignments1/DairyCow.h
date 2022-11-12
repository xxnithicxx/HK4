#pragma once

#include <iostream>
#include <string>
#include "ID.h"
using namespace std;

class DairyCow
{
private:
    int _identifier;
    int _weight;
    int _age;

public:
    int getAge() const;
    int getWeight() const;
    int getIdentifier() const;

    void setAge(int age);
    void setWeight(int weight);

public:
    DairyCow(int weight, int age);
    DairyCow();
    DairyCow(const DairyCow &cow);

    DairyCow &operator=(const DairyCow &other);

    bool checkAge(int age) const;
    bool checkWeight(int weight) const;

    string toString() const;
};

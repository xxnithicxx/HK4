#pragma once

#include <iostream>
#include <string>
#include "ID.h"
using namespace std;

class Goat
{
public:
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
    Goat(int weight, int age);
    Goat();
    Goat(const Goat& goat);

    Goat& operator=(const Goat& other);

    bool checkAge(int age) const;
    bool checkWeight(int weight) const;
    
    string toString() const;
};
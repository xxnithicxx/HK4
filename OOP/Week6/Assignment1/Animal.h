#pragma once

#include <iostream>
using namespace std;

class Animal
{
protected:
    int _identifier;
    int _weight;
    int _age;

public:
    int getAge() const
    {
        return _age;
    }

    int getWeight() const
    {
        return _weight;
    }

    int getIdentifier() const
    {
        return _identifier;
    }

    void setAge(int age)
    {
        _age = age;
    }

    void setWeight(int weight)
    {
        _weight = weight;
    }

    bool checkAge(int age) const
    {
        return age > 0;
    }

    bool checkWeight(int weight) const
    {
        return weight > 0;
    }

    virtual string toString() const = 0;
};

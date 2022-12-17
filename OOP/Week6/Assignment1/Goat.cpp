#include "Goat.h"

Goat::Goat(int weight, int age)
{
    _identifier = IDGenerator::getInstance()->getID();
    if (checkWeight(weight))
    {
        _weight = weight;
    }
    else
    {
        cout << "Invalid weight" << endl;
        _weight = 0;
    }

    if (checkAge(age))
    {
        _age = age;
    }
    else
    {
        cout << "Invalid age" << endl;
        _age = 0;
    }
}

Goat::Goat()
{
    _identifier = IDGenerator::getInstance()->getID();
    _weight = 0;
    _age = 0;
}

Goat::Goat(const Goat &other)
{
    _identifier = IDGenerator::getInstance()->getID();
    _weight = other._weight;
    _age = other._age;
}

string Goat::toString() const
{
    string result = "Goat(" + to_string(_identifier) + "): " + to_string(_weight) + "kg, " + to_string(_age) + " years old";
    return result;
}

Goat &Goat::operator=(const Goat &other)
{
    if (this != &other)
    {
        _identifier = IDGenerator::getInstance()->getID();
        _weight = other._weight;
        _age = other._age;
    }
    return *this;
}
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

int Goat::getAge() const
{
    return _age;
}

int Goat::getWeight() const
{
    return _weight;
}

int Goat::getIdentifier() const
{
    return _identifier;
}

void Goat::setAge(int age)
{
    if (checkAge(age))
    {
        _age = age;
    }
    else
    {
        _age = 0;
    }
}

void Goat::setWeight(int weight)
{
    if (checkWeight(weight))
    {
        _weight = weight;
    }
    else
    {
        _weight = 0;
    }
}

bool Goat::checkAge(int age) const
{
    return age > 0;
}

bool Goat::checkWeight(int weight) const
{
    return weight > 0;
}
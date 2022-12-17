#include "DairyCow.h"

DairyCow::DairyCow(int weight, int age)
{
    _identifier = IDGenerator::getInstance()->getID();
    _weight = weight;
    _age = age;
}

DairyCow::DairyCow()
{
    _identifier = IDGenerator::getInstance()->getID();
    _weight = 0;
    _age = 0;
}

DairyCow::DairyCow(const DairyCow &other)
{
    _identifier = IDGenerator::getInstance()->getID();
    _weight = other._weight;
    _age = other._age;
}

string DairyCow::toString() const
{
    string result = "Cow(" + to_string(_identifier) + "): " + to_string(_weight) + "kg, " + to_string(_age) + " years old";
    return result;
}

DairyCow &DairyCow::operator=(const DairyCow &other)
{
    if (this != &other)
    {
        _identifier = IDGenerator::getInstance()->getID();
        _weight = other._weight;
        _age = other._age;
    }
    return *this;
}
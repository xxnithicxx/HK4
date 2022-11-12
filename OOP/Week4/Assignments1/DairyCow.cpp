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

int DairyCow::getAge() const
{
    return _age;
}

int DairyCow::getWeight() const
{
    return _weight;
}

int DairyCow::getIdentifier() const
{
    return _identifier;
}

void DairyCow::setAge(int age)
{
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

void DairyCow::setWeight(int weight)
{
    if (checkWeight(weight))
    {
        _weight = weight;
    }
    else
    {
        cout << "Invalid weight" << endl;
        _weight = 0;
    }
}

bool DairyCow::checkAge(int age) const
{
    return age > 0;
}

bool DairyCow::checkWeight(int weight) const
{
    return weight > 0;
}
/**
 * @file Decorator.cpp
 * @author xxnithicxx (21127439)
 * @brief Make a decorator pattern of Laptop
 * @date 12-11-2022
 *
 */
#include <iostream>
#include <string>
using namespace std;

// Make interface for base laptop (Component)
class Laptop
{
public:
    virtual int getPrice() = 0;
    virtual string getDescription() = 0;
};

// Make class for base laptop (Concrete Component)
class BaseLaptop : public Laptop
{
public:
    int getPrice() override
    {
        return 1000;
    }
    string getDescription() override
    {
        return "Base Laptop";
    }
};

// Make interface for decorator (Base Decorator)
class LaptopAddOn : public Laptop
{
protected:
    Laptop *laptop; // This is the wrapped object

public:
    LaptopAddOn(Laptop *laptop): laptop(laptop) {}

    int getPrice() override
    {
        return laptop->getPrice();
    }

    string getDescription() override
    {
        return laptop->getDescription();
    }
};

// Make class for decorator (Concrete Decorator)
class LaptopMemory : public LaptopAddOn
{
public:
    LaptopMemory(Laptop *laptop): LaptopAddOn(laptop) {}

    int getPrice() override
    {
        return LaptopAddOn::getPrice() + 100;
    }

    string getDescription() override
    {
        return LaptopAddOn::getDescription() + " + 8GB Memory";
    }
};

class LaptopSSD : public LaptopAddOn
{
public:
    LaptopSSD(Laptop *laptop): LaptopAddOn(laptop) {}

    int getPrice() override
    {
        return LaptopAddOn::getPrice() + 200;
    }

    string getDescription() override
    {
        return LaptopAddOn::getDescription() + " + 256GB SSD";
    }
};

int main()
{
    Laptop *laptop = new BaseLaptop();
    cout << laptop->getDescription() << " - $" << laptop->getPrice() << endl;

    laptop = new LaptopMemory(laptop);
    cout << laptop->getDescription() << " - $" << laptop->getPrice() << endl;

    laptop = new LaptopSSD(laptop);
    cout << laptop->getDescription() << " - $" << laptop->getPrice() << endl;

    return 0;
}
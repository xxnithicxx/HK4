#include <iostream>
using namespace std;

class Chair
{
public:
    virtual void sit() = 0;
};

class VictorianChair : public Chair
{
public:
    void sit()
    {
        cout << "Victorian Chair" << endl;
    }
};

class ModernChair : public Chair
{
public:
    void sit()
    {
        cout << "Modern Chair" << endl;
    }
};


class Sofa
{
public:
    virtual void lie() = 0;
};

class VictorianSofa : public Sofa
{
public:
    void lie()
    {
        cout << "Victorian Sofa" << endl;
    }
};

class ModernSofa : public Sofa
{
public:
    void lie()
    {
        cout << "Modern Sofa" << endl;
    }
};

class FurnitureFactory // Abstract Factory Interface
{
public:
    virtual Chair* createChair() = 0;
    virtual Sofa* createSofa() = 0;
};

class VictorianFurnitureFactory : public FurnitureFactory
{
public:
    Chair* createChair()
    {
        return new VictorianChair;
    }

    Sofa* createSofa()
    {
        return new VictorianSofa;
    }
};

class ModernFurnitureFactory : public FurnitureFactory
{
public:
    Chair* createChair()
    {
        return new ModernChair;
    }

    Sofa* createSofa()
    {
        return new ModernSofa;
    }
};

int main()
{
    FurnitureFactory* factory = new VictorianFurnitureFactory;
    Chair* chair = factory->createChair();
    Sofa* sofa = factory->createSofa();
    chair->sit();
    sofa->lie();

    factory = new ModernFurnitureFactory;
    chair = factory->createChair();
    sofa = factory->createSofa();
    chair->sit();
    sofa->lie();

    return 0;
}
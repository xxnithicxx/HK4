#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string _details;

public:
    virtual void info()
    {
        cout << _details << endl;
    }

    virtual void addDetails(string details)
    {
        _details += details;
    }
};

class CarBuilder
{
public:
    virtual void reset() = 0;
    virtual void setSeats(int) = 0;
    virtual void setEngine(string) = 0;
    virtual void setDoors(int) = 0;
    virtual void setWheels(int) = 0;
    /*
        >> virtual Car* getCar() = 0;
        This method is wrong because Builder didn't bound to the product it should return.
        Example: CarBuilder can build ToyCar, FigturCar, RealCar, etc.
        More details: Dive into Design Pattern, page 117. 
    */
};

class GasCarBuilder : public CarBuilder
{
private:
    Car *_car;

public:
    GasCarBuilder()
    {
        _car = new Car();
        _car->addDetails("Gas Car \n");
    }

    void reset()
    {
        _car = new Car();
        _car->addDetails("Gas Car \n");
    }

    void setSeats(int seats)
    {
        _car->addDetails("Seats: " + to_string(seats) + " \n");
    }

    void setEngine(string engine)
    {
        _car->addDetails("Engine: " + engine + " \n");
    }

    void setDoors(int doors)
    {
        _car->addDetails("Doors: " + to_string(doors) + " \n");
    }

    void setWheels(int wheels)
    {
        _car->addDetails("Wheels: " + to_string(wheels) + " \n");
    }

    Car *getCar()
    {
        return _car;
    }
};

class ElectricCarBuilder : public CarBuilder
{
private:
    Car *_car;

public:
    ElectricCarBuilder()
    {
        _car = new Car();
        _car->addDetails("Electric Car \n");
    }

    void reset()
    {
        _car = new Car();
        _car->addDetails("Electric Car \n");
    }

    void setSeats(int seats)
    {
        _car->addDetails("Seats: " + to_string(seats) + " \n");
    }

    void setEngine(string engine)
    {
        _car->addDetails("Engine: " + engine + " \n");
    }

    void setDoors(int doors)
    {
        _car->addDetails("Doors: " + to_string(doors) + " \n");
    }

    void setWheels(int wheels)
    {
        _car->addDetails("Wheels: " + to_string(wheels) + " \n");
    }

    Car *getCar()
    {
        return _car;
    }
};

class Director
{
private:
    CarBuilder *_carBuilder;

public:
    void setCarBuilder(CarBuilder *carBuilder)
    {
        _carBuilder = carBuilder;
    }

    void buildCar()
    {
        _carBuilder->reset();
        _carBuilder->setSeats(4);
        _carBuilder->setEngine("V8");
        _carBuilder->setDoors(2);
        _carBuilder->setWheels(4);
    }

    void buildSportsCar()
    {
        _carBuilder->reset();
        _carBuilder->setSeats(2);
        _carBuilder->setEngine("V12");
        _carBuilder->setDoors(2);
        _carBuilder->setWheels(4);
    }

    void buildTruck()
    {
        _carBuilder->reset();
        _carBuilder->setSeats(2);
        _carBuilder->setEngine("V8");
        _carBuilder->setDoors(2);
        _carBuilder->setWheels(8);
    }
};

int main()
{
    Director director;
    GasCarBuilder gasCarBuilder;
    ElectricCarBuilder electricCarBuilder;

    director.setCarBuilder(&gasCarBuilder);
    director.buildCar();
    Car *car = gasCarBuilder.getCar();
    car->info();

    director.setCarBuilder(&electricCarBuilder);
    director.buildSportsCar();
    car = electricCarBuilder.getCar();
    car->info();

    return 0;
}
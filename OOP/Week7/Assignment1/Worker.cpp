#include "Worker.h"

Worker::Worker(): Employee()
{
    _items = 0;
}

Worker::Worker(string id, string name, string hireDate, string address, int items): Employee(id, name, hireDate, address)
{
    _items = items;
}

Worker::Worker(string id, string name, string hireDate, string address): Employee(id, name, hireDate, address)
{
    _items = 0;
}

Worker::Worker(string id, string name, string hireDate): Employee(id, name, hireDate)
{
    _items = 0;
}

Worker::Worker(string id, string name): Employee(id, name)
{
    _items = 0;
}

Worker::Worker(string id): Employee(id)
{
    _items = 0;
}

void Worker::input()
{
    Employee::input();
    cout << "Enter number of items: ";
    cin >> _items;
}

void Worker::output()
{
    Employee::output();
    cout << "Number of items: " << _items << endl;
}

int Worker::getSalary()
{
    return _items * 20;
}
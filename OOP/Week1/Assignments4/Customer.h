#pragma once

#include "Cart.h"
#include "Rank.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Customer
{
private:
    string _name;
    string _address;
    string _DoB;
    Cart _cart;
    Rank _rank;

public:
    bool pay(); // Add regional to pay
    void reviewProduct(Product product, float rating);
    bool isBirthday();
    bool isShipable();
    bool refund(string cartID);
};

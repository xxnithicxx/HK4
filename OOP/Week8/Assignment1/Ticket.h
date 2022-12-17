#pragma once

#include <iostream>
#include "Object.h"
using namespace std;

class Ticket : public Object
{
protected:
    string _filmTitle;
    string _startTime;
    string _roomName;
    int _priceOfFoodAndDrink;
    double _ticketFactor;

public:
    string getStartTime()
    {
        return _startTime;
    }

    string getRoomName()
    {
        return _roomName;
    }

    string getFilmTitle()
    {
        return _filmTitle;
    }

    int getPriceOfFoodAndDrink()
    {
        return _priceOfFoodAndDrink;
    }

public:
    virtual double price() = 0;

    bool operator<(Ticket &ticket)
    {
        if (toString() == ticket.toString())
        {
            return price() < ticket.price();
        }
        return toString() < ticket.toString();
    }
};
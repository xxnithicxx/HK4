#pragma once

#include <iostream>
#include "Ticket.h"
using namespace std;

class RegularTicket : public Ticket
{
public:
    RegularTicket(string filmTitle, string startTime, string roomName, int priceOfFoodAndDrink)
    {
        _filmTitle = filmTitle;
        _startTime = startTime;
        _roomName = roomName;
        _priceOfFoodAndDrink = priceOfFoodAndDrink;
        _ticketFactor = 1.0;
    }

    double price()
    {
        return _ticketFactor * 80000 + _priceOfFoodAndDrink;
    }

    string toString()
    {
        return "RegularTicket";
    }
};
#pragma once

#include <iostream>
#include "Ticket.h"
using namespace std;

class ComboTicket : public Ticket
{
public:
    ComboTicket(string filmTitle, string startTime, string roomName, int priceOfFoodAndDrink)
    {
        _filmTitle = filmTitle;
        _startTime = startTime;
        _roomName = roomName;
        _priceOfFoodAndDrink = priceOfFoodAndDrink;
        _ticketFactor = 1.5;
    }

    double price()
    {
        return _ticketFactor * 80000 + _priceOfFoodAndDrink * 0.8;
    }

    string toString()
    {
        return "ComboTicket";
    }
};
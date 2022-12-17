#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "ComboTicket.h"
#include "RegularTicket.h"
#include "Time.h"
using namespace std;

class TicketManager
{
private:
    vector<Ticket *> _tickets;

public:
    void inputTickets();
    void sortTickets();
    void saveTickets();
    void summarizeTickets();

    void testCase();
};

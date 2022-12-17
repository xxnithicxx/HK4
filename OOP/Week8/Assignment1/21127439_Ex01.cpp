#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "TicketManager.h"
using namespace std;

int main()
{
    TicketManager ticketManager;
    ticketManager.testCase();
    // ticketManager.inputTickets();
    ticketManager.sortTickets();
    ticketManager.saveTickets();
    ticketManager.summarizeTickets();
    return 0;
}
#include "TicketManager.h"

void TicketManager::inputTickets()
{
    int n;
    cout << "Enter number of tickets: ";
    cin >> n;
    _flushall();
    for (int i = 0; i < n; i++)
    {
        string filmTitle, startTime, roomName;
        int priceOfFoodAndDrink;
        cout << "Enter film title: ";
        getline(cin, filmTitle);
        cout << "Enter start time: ";
        cin >> startTime;
        _flushall();

        if (!Time::isTime(startTime))
        {
            i--;
            cout << "Wrong time format (hh:mm)!" << endl;
            continue;
        }

        cout << "Enter room name: ";
        getline(cin, roomName);
        cout << "Enter price of food and drink: ";
        cin >> priceOfFoodAndDrink;
        cout << "Enter ticket type (1: Regular, 2: Combo): ";
        int ticketType;
        cin >> ticketType;
        _flushall();
        if (ticketType == 1)
        {
            _tickets.push_back(new RegularTicket(filmTitle, startTime, roomName, priceOfFoodAndDrink));
        }
        else
        {
            _tickets.push_back(new ComboTicket(filmTitle, startTime, roomName, priceOfFoodAndDrink));
        }
    }
}

void TicketManager::sortTickets()
{
    for (int i = 0; i < _tickets.size() - 1; i++)
    {
        for (int j = i + 1; j < _tickets.size(); j++)
        {
            if (*_tickets[i] < *_tickets[j])
            {
                Ticket *temp = _tickets[i];
                _tickets[i] = _tickets[j];
                _tickets[j] = temp;
            }
        }
    }
}

void TicketManager::saveTickets()
{
    ofstream fout("tickets.txt");
    for (int i = 0; i < _tickets.size(); i++)
    {
        fout << _tickets[i]->toString() << "," << _tickets[i]->getFilmTitle() << "," << _tickets[i]->getStartTime() << "," << _tickets[i]->getRoomName() << "," << _tickets[i]->getPriceOfFoodAndDrink() << "," << _tickets[i]->price() << endl;
    }
    fout.close();
}

void TicketManager::summarizeTickets()
{
    cout << setw(10) << "Range" << setw(10) << "#Regular" << setw(10) << "#Combo" << endl;

    for (int i = 0; i < 24; i++)
    {
        int regular = 0, combo = 0;
        for (int j = 0; j < _tickets.size(); j++)
        {
            int hour = stoi(_tickets[j]->getStartTime().substr(0, 2));
            if (hour == i)
            {
                if (_tickets[j]->toString() == "RegularTicket")
                {
                    regular++;
                }
                else
                {
                    combo++;
                }
            }
        }
        cout << setw(10) << i << setw(10) << regular << setw(10) << combo << endl;
    }
}

void TicketManager::testCase()
{
    _tickets.push_back(new RegularTicket("film1", "10:00", "room1", 100000));
    _tickets.push_back(new RegularTicket("film2", "05:00", "room6", 130000));
    _tickets.push_back(new RegularTicket("film3", "20:00", "room7", 50000));
    _tickets.push_back(new RegularTicket("film4", "08:00", "room1", 20000));
    _tickets.push_back(new RegularTicket("film5", "12:00", "room2", 30000));
    _tickets.push_back(new RegularTicket("film6", "15:00", "room3", 40000));
    _tickets.push_back(new RegularTicket("film7", "18:00", "room4", 50000));
    _tickets.push_back(new ComboTicket("film8", "21:00", "room5", 60000));
    _tickets.push_back(new ComboTicket("film9", "23:00", "room6", 70000));
    _tickets.push_back(new ComboTicket("film10", "22:00", "room7", 80000));
    _tickets.push_back(new ComboTicket("film11", "19:00", "room1", 90000));
    _tickets.push_back(new ComboTicket("film12", "16:00", "room2", 100000));
    _tickets.push_back(new ComboTicket("film13", "13:00", "room3", 110000));
    _tickets.push_back(new ComboTicket("film14", "10:00", "room4", 120000));
};
#include "Shipper.h"

void Shipper::setShipper(string name, string specialNote, string website)
{
    _name = name;
    _specialNote = specialNote;
    _website = website;
}

void Shipper::addLocation(string location)
{
    _location.push_back(location);
}

int Shipper::calculateShippingFee(string location)
{
    if (location == "HCM")
    {
        return 15000;
    }
    else if (location == "HN")
    {
        return 20000;
    }
    else 
    {
        return 30000;
    }
}

void Shipper::printShipper()
{
    cout << "Name: " << _name << endl;
    cout << "Special Note: " << _specialNote << endl;
    cout << "Website: " << _website << endl;
    cout << "Price: " << _price << endl;
    cout << "Location: ";
    for (int i = 0; i < _location.size(); i++)
    {
        cout << _location[i] << " ";
    }
    cout << endl;
}

bool Shipper::isFreeShipping(Rank rank)
{
    if (rank.getRank() >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Shipper::isSaveWebsite()
{
    if (_website.find("https://") != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
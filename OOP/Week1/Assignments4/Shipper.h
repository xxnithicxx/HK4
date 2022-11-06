#pragma once

#include "Rank.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shipper
{
private:
    string _name;
    string _specialNote;
    string _website;
    int _price;
    vector<string> _location;

public:
    void setShipper(string name, string specialNote, string website);

public:
    void addLocation(string location);
    int calculateShippingFee(string location);
    void printShipper();
    bool isFreeShipping(Rank rank);
    bool isSaveWebsite();
};

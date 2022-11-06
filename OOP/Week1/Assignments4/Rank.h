#pragma once

#include "Product.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// extern vector<string> rankTitle = {"Bronze", "Silver", "Gold", "Platinum", "Diamond"};

class Rank
{
private:
    string _name;
    float _discount;
    int _numberOfBill;
    int _totalSpent;
    int _savedMoney;
    vector<string> rankTitle = {"Bronze", "Silver", "Gold", "Platinum", "Diamond"};

public:
    void setRank(string name, float discount, int numberOfBill, int totalSpent, int savedMoney);
    int getRank() const;
    float getDiscount() const { return _discount; };

public:
    void updateRank(Product product);
    void printRank();
    string nextRank();
    int billToNextRank();
    float percentOfSavedMoney();
};
#include "Rank.h"

void Rank::setRank(string name, float discount, int numberOfBill, int totalSpent, int savedMoney)
{
    _name = name;
    _discount = discount;
    _numberOfBill = numberOfBill;
    _totalSpent = totalSpent;
    _savedMoney = savedMoney;
}

int Rank::getRank() const
{
    for (int i = 0; i < rankTitle.size(); i++)
    {
        if (rankTitle[i] == _name)
        {
            return i;
        }
    }
    return -1;
}

void Rank::updateRank(Product product)
{
    _numberOfBill++;
    _totalSpent += product.getPrice();
    _savedMoney += product.getPrice() * _discount;

    switch (_numberOfBill)
    {
    case 10:
        _name = rankTitle[0];
        _discount = 0.05;
        break;
    case 20:
        _name = rankTitle[1];
        _discount = 0.1;
        break;
    case 30:
        _name = rankTitle[2];
        _discount = 0.15;
        break;
    case 40:
        _name = rankTitle[3];
        _discount = 0.2;
        break;
    case 50:
        _name = rankTitle[4];
        _discount = 0.25;
        break;
    default:
        break;
    }
}

void Rank::printRank()
{
    cout << "Rank: " << _name << endl;
    cout << "Discount: " << _discount << endl;
    cout << "Number of bill: " << _numberOfBill << endl;
    cout << "Total spent: " << _totalSpent << endl;
    cout << "Saved money: " << _savedMoney << endl;
}

string Rank::nextRank()
{
    int index = 0;
    for (int i = 0; i < rankTitle.size(); i++)
    {
        if (rankTitle[i] == _name)
        {
            index = i;
            break;
        }
    }
    if (index == rankTitle.size() - 1)
    {
        return "You are the highest rank";
    }
    else
    {
        return rankTitle[index + 1];
    }
}

int Rank::billToNextRank()
{
    int index = 0;
    for (int i = 0; i < rankTitle.size(); i++)
    {
        if (rankTitle[i] == _name)
        {
            index = i;
            break;
        }
    }

    if (index == rankTitle.size() - 1)
    {
        return 0;
    }
    else
    {
        return 10 * (index + 1) - _numberOfBill;
    }
}

float Rank::percentOfSavedMoney()
{
    return (float) _savedMoney * 100 / (float) _totalSpent;
}
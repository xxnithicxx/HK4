#include "Customer.h"

bool Customer::pay()
{
    bool checkShip = isShipable();
    bool checkBirthday = isBirthday();
    if (checkShip == true && checkBirthday == true)
    {
        float discount = _rank.getDiscount();
        // Get city of customer
        string city = _address.substr(_address.find_last_of(" ") + 1);

        if (_cart.getNumberOfProduct() != 0)
        {
            discount += _cart.getProduct(0).regionalDiscount(city);
        }
        else
        {
            return false;
        }

        int birthdayDiscount = 0;
        if (isBirthday() == true)
        {
            birthdayDiscount = 20000;
        }

        int shippingFee = _cart.getShipper().calculateShippingFee(city);
        if (_cart.getShipper().isFreeShipping(_rank) == true)
        {
            shippingFee = 0;
        }

        int total = _cart.total() * (1 - discount) - birthdayDiscount + shippingFee;
        if (total < 0)
            total = 0;
        cout << "Total: " << total << endl;

        for (int i = 0; i < _cart.getNumberOfProduct(); i++)
        {
            _rank.updateRank(_cart.getProduct(i));
        }

        cout << "You have :" << _rank.billToNextRank() << " to rank " << _rank.nextRank() << endl;

        return true;
    }
    else
    {
        return false;
    }
}

bool Customer::isBirthday()
{
    string date = _DoB;
    string month = date.substr(3, 2);
    string day = date.substr(0, 2);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int monthNow = 1 + ltm->tm_mon;
    int dayNow = ltm->tm_mday;
    if (monthNow == stoi(month) && dayNow == stoi(day))
    {
        return true;
    }
    return false;
}

bool Customer::isShipable()
{
    if (_cart.getShipper().isFreeShipping(_rank))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Customer::refund(string cartID)
{
    if (_cart.getID() == cartID)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Customer::reviewProduct(Product product, float rating)
{
    product.addRating(rating);
}
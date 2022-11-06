#include "Product.h"

string Product::checkRating()
{
    if (_rating >= 4.5)
    {
        return "Excellent";
    }
    else if (_rating >= 4)
    {
        return "Good";
    }
    else if (_rating >= 3.5)
    {
        return "Average";
    }
    else if (_rating >= 3)
    {
        return "Bad";
    }
    else
    {
        return "Very bad";
    }
}

float Product::regionalDiscount(string regional)
{
    if (regional == "HCM" || regional == "HN")
    {
        return 0;
    }
    else if (regional == "DN")
    {
        return 0.01;
    }
    else if (regional == "CT")
    {
        return 0.02;
    }
    else
    {
        return 0.05;
    }
}

void Product::printProduct()
{
    cout << "Name: " << _name << endl;
    cout << "ID: " << _id << endl;
    cout << "Price: " << _price << endl;
    cout << "Quantity: " << _quantity << endl;
    cout << "Rating: " << _rating << endl;
}

int Product::totalPrice()
{
    return _price * _quantity;
}

bool Product::isTaxFree()
{
    if (_price >= 1000000 || _name == "Bread" || _name == "Milk")
    {
        return true;
    }
    else
    {
        return false;
    }
}

float Product::addRating(float rating)
{
    _rating = (_rating + rating) / 2;
    return _rating;
}
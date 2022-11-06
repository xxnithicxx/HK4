#include "Cart.h"

void Cart::addProduct(Product product)
{
    _listProduct.push_back(product);
}

void Cart::removeProduct(string id)
{
    for (int i = 0; i < _listProduct.size(); i++)
    {
        if (_listProduct[i].getID() == id)
        {
            _listProduct.erase(_listProduct.begin() + i);
        }
    }
}

int Cart::total()
{
    int total = 0;
    for (int i = 0; i < _listProduct.size(); i++)
    {
        total += _listProduct[i].totalPrice() * (1 - _discount) * (1 + _listProduct[i].isTaxFree());
    }
    return total;
}

bool Cart::addGiftcode(string giftcode)
{
    if (giftcode == "GIFT2022")
    {
        _discount = 0.1;
        total();
        return true;
    }
    total();
    return false;
}

void Cart::printProduct()
{
    for (int i = 0; i < _listProduct.size(); i++)
    {
        _listProduct[i].printProduct();
    }
}
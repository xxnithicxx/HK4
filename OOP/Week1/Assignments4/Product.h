#pragma once

#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    string _name;
    string _id;
    int _price;
    int _quantity;
    float _rating;

public:
    void setProduct(string name, string id, int price, int quantity, float rated);
    void updateProduct(int price, int quantity);
    int getPrice() { return _price; };
    string getID() { return _id; };

public:
    string checkRating();
    float regionalDiscount(string regional);
    void printProduct();
    int totalPrice();
    bool isTaxFree();
    float addRating(float rating);
};
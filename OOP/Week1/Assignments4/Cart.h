#pragma once

#include "Shipper.h"
#include "Product.h"
#include <iostream>
#include <string>
using namespace std;

class Cart {
private:
    string _id;
    int _total;
    string _date;
    Shipper _shipper;
    vector<Product> _listProduct;
    int _discount;

public:
    Product getProduct(int index) { return _listProduct[index]; };
    Shipper getShipper() { return _shipper; };
    int getNumberOfProduct() { return _listProduct.size(); };
    string getID() { return _id; };

public:
    void addProduct(Product product);
    void removeProduct(string id);
    int total();
    bool addGiftcode(string giftcode);
    void printProduct();
};
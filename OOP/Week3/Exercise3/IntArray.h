#pragma once

#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    int getData()
    {
        return this->data;
    }
    Node* getNext()
    {
        return this->next;
    }
    friend class IntArray;
};

class IntArray
{
private:
    Node *head;
    int _size;
    int _capacity;

public:
    IntArray();
    IntArray(int capacity);
    IntArray(int *arr, int size);
    IntArray(const IntArray &arr);

    IntArray &operator=(const IntArray &arr);
    friend ostream &operator<<(ostream &os, const IntArray &arr);
    friend istream &operator>>(istream &is, IntArray &arr);
    int &operator[](int index);
    operator int() const;

    ~IntArray();

    bool addTail(int data);
};
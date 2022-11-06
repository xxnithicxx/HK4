#pragma once

#include <iostream>
#include "Node.h"
using namespace std;

class LinkedListQueue {
private:
    Node* _head;
    Node* _tail;
    int _capacity;
    int _num;

public:
    void Init(int capacity);
    void Enqueue(int data);
    void Dequeue();
    int Peek();
    bool IsEmpty();
    bool IsFull();
    void clear();
};

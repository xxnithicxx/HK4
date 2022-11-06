#pragma once

#include <iostream>

class Node {
private:
    int _data;
    Node* _next;

public:
    void Init(int data, Node* next);
    int getData() { return _data; };
    Node* getNext() { return _next; };
    void setData(int data) { _data = data; };
    void setNext(Node* next) { _next = next; };
};

void Node::Init(int data, Node* next) {
    _data = data;
    _next = next;
}
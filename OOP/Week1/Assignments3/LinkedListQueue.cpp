#include "LinkedListQueue.h"

void LinkedListQueue::Init(int capacity) {
    _head = new Node;
    _tail = new Node;
    _head->setNext(_tail);
    _tail->setNext(_tail);
    _capacity = capacity;
    _num = 0;
}

void LinkedListQueue::Enqueue(int data) {
    if (IsFull()) {
        cout << "Queue is full" << endl;
        return;
    }
    Node* newNode = new Node;
    newNode->Init(data, _tail);
    Node* temp = _head;
    while (temp->getNext() != _tail) {
        temp = temp->getNext();
    }
    temp->setNext(newNode);
    _num++;
}

void LinkedListQueue::Dequeue() {
    if (IsEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = _head->getNext();
    _head->setNext(temp->getNext());
    delete temp;
    _num--;
}

int LinkedListQueue::Peek() {
    if (IsEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return _head->getNext()->getData();
}

bool LinkedListQueue::IsEmpty() {
    return _num == 0;
}

bool LinkedListQueue::IsFull() {
    return _num == _capacity;
}

void LinkedListQueue::clear() {
    while (!IsEmpty()) {
        Dequeue();
    }
}


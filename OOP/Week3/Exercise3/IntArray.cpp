#include "IntArray.h"

IntArray::IntArray()
{
    this->head = NULL;
    this->_size = 0;
    this->_capacity = 0;
}

IntArray::IntArray(int capacity)
{
    this->head = NULL;
    this->_size = 0;
    this->_capacity = capacity;
}

IntArray::IntArray(int *arr, int size)
{
    this->head = NULL;
    this->_size = size;
    this->_capacity = size;

    for (int i = 0; i < size; i++)
    {
        this->addTail(arr[i]);
    }
}

IntArray::IntArray(const IntArray &arr)
{
    this->head = NULL;
    this->_size = arr._size;
    this->_capacity = arr._capacity;

    Node *p = arr.head;
    while (p != NULL)
    {
        this->addTail(p->data);
        p = p->next;
    }
}

IntArray &IntArray::operator=(const IntArray &arr)
{
    this->head = NULL;
    this->_size = arr._size;
    this->_capacity = arr._capacity;

    Node *p = arr.head;
    while (p != NULL)
    {
        this->addTail(p->data);
        p = p->next;
    }

    return *this;
}

IntArray::~IntArray()
{
    Node *p = this->head;
    while (p != NULL)
    {
        Node *q = p;
        p = p->next;
        delete q;
    }
}

ostream &operator<<(ostream &os, const IntArray &arr)
{
    Node *p = arr.head;
    while (p != NULL)
    {
        os << p->getData() << " ";
        p = p->getNext();
    }
    os << endl;
    return os;
}

istream &operator>>(istream &is, IntArray &arr)
{
    ~IntArray();
    cout << "Enter capacity: ";
    is >> arr._capacity;

    int size;
    do {
        cout << "Enter size: ";
        is >> size;
    } while (size > arr._capacity);
    
    arr._size = size;

    for (int i = 0; i < size; i++)
    {
        int data;
        is >> data;
        arr.addTail(data);
    }

    return is;
}

int &IntArray::operator[](int index)
{
    Node *p = this->head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    return p->data;
}

IntArray::operator int() const
{
    return this->_size;
}

bool IntArray::addTail(int data)
{
    Node *newNode = new Node(data);
    if (this->head == NULL)
    {
        this->head = newNode;
        return true;
    }
    Node *temp = this->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return true;
}
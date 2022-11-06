#include <stdio.h>
#include <iostream>

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

    friend class LinkedList;
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void add(int data)
    {
        Node *node = new Node(data);
        if (this->head == NULL)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            this->tail->next = node;
            this->tail = node;
        }
        this->size++;
    }

    void print()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void remove(int data)
    {
        Node *temp = this->head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (prev == NULL)
                {
                    this->head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                this->size--;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    int getSize()
    {
        return this->size;
    }
};

int main(int argc, char **argv)
{
    
}
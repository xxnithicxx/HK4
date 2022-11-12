#pragma once

#include <iostream>
#include <memory>
using namespace std;

class IDGenerator
{
private:
    inline static shared_ptr<IDGenerator> _instance = nullptr;
    int *_pollID;
    int _size;

    IDGenerator(){
        srand(time(NULL));
        _size = 100;
        _pollID = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            _pollID[i] = i + 1;
        }
    }
    
public:
    static shared_ptr<IDGenerator> getInstance(){
        if (_instance == nullptr)
        {
            IDGenerator *temp = new IDGenerator();
            _instance = shared_ptr<IDGenerator>(temp);
        }
        return _instance;
    }

    int getID(){
        // Randomly pick an ID from the pool
        int index = rand() % _size;
        int id = _pollID[index];
        // Remove the ID from the pool
        swap(_pollID[index], _pollID[_size - 1]);
        _size--;
        return id;
    }
};
#pragma once

#include <iostream>
using namespace std;

class MyIntArray{
private:
    int *_arr;
    int _size;
public:
    MyIntArray(int *arr, int size);
    MyIntArray(int argc, char const *argv[]);
    MyIntArray(int size);
    MyIntArray();
    MyIntArray(const MyIntArray &other);

    void print(){
        for(int i = 0; i < _size; i++){
            cout << _arr[i] << " ";
        }
        cout << endl;
    }
};
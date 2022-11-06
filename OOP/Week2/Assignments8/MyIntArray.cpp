#include "MyIntArray.h"

MyIntArray::MyIntArray(int *arr, int size){
    this->_size = size;
    this->_arr = new int[size];
    for(int i = 0; i < size; i++){
        this->_arr[i] = arr[i];
    }
}

MyIntArray::MyIntArray(int argc, char const *argv[]){
    this->_size = argc - 1;
    this->_arr = new int[argc - 1];
    for(int i = 0; i < argc; i++){
        this->_arr[i] = atoi(argv[i + 1]);
    }
}

MyIntArray::MyIntArray(int size){
    this->_size = size;
    this->_arr = new int[size];
    for(int i = 0; i < size; i++){
        this->_arr[i] = 0;
    }
}

MyIntArray::MyIntArray(){
    this->_size = 0;
    this->_arr = NULL;
}

MyIntArray::MyIntArray(const MyIntArray &other){
    this->_size = other._size;
    this->_arr = new int[other._size];
    for(int i = 0; i < other._size; i++){
        this->_arr[i] = other._arr[i];
    }
}
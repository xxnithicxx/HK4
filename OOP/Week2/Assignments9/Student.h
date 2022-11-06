#pragma once

#include <iostream>
using namespace std;

class Student
{
private:
    int _id;
    char *_fullname;
    char *_address;
    double _gpa;

public:
    Student(int id, char *fullname, char *address, double gpa);
    Student(int id, char *fullname, char *address);
    Student(int id, char *fullname);
    Student(int id);
    Student();

    void print()
    {
        cout << "ID: " << _id << endl;
        cout << "Fullname: " << _fullname << endl;
        cout << "Address: " << _address << endl;
        cout << "GPA: " << _gpa << endl;
    }
};
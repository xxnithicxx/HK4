#pragma once

#include <iostream>
#include <string>
using namespace std;

class Lecturer
{
private:
    int _id;
    string _fullname;
    string _degree;
    int _numOfCourses;

public:
    Lecturer(int id, string fullname, string degree, int numOfCourses);
    Lecturer(int id, string fullname, string degree);
    Lecturer(int id, string fullname);
    Lecturer(int id);
    Lecturer();

    void print(){
        cout << "ID: " << _id << endl;
        cout << "Fullname: " << _fullname << endl;
        cout << "Degree: " << _degree << endl;
        cout << "Number of courses: " << _numOfCourses << endl;
    }

};
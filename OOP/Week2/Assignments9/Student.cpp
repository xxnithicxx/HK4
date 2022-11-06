#include "Student.h"

Student::Student(int id, char *fullname, char *address, double gpa)
{
    _id = id;
    _fullname = fullname;
    _address = address;
    _gpa = gpa;
}

Student::Student(int id, char *fullname, char *address)
{
    _id = id;
    _fullname = fullname;
    _address = address;
    _gpa = 0;
}

Student::Student(int id, char *fullname)
{
    _id = id;
    _fullname = fullname;
    _address = "";
    _gpa = 0;
}

Student::Student(int id)
{
    _id = id;
    _fullname = "";
    _address = "";
    _gpa = 0;
}

Student::Student()
{
    _id = 0;
    _fullname = "";
    _address = "";
    _gpa = 0;
}
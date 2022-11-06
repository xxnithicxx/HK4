#include "Lecturer.h"

Lecturer::Lecturer(int id, string fullname, string degree, int numOfCourses)
{
    _id = id;
    _fullname = fullname;
    _degree = degree;
    if (numOfCourses < 0)
        _numOfCourses = 0;
    else
        _numOfCourses = numOfCourses;
}

Lecturer::Lecturer(int id, string fullname, string degree)
{
    _id = id;
    _fullname = fullname;
    _degree = degree;
    _numOfCourses = 0;
}

Lecturer::Lecturer(int id, string fullname)
{
    _id = id;
    _fullname = fullname;
    _degree = "";
    _numOfCourses = 0;
}

Lecturer::Lecturer(int id)
{
    _id = id;
    _fullname = "";
    _degree = "";
    _numOfCourses = 0;
}

Lecturer::Lecturer()
{
    _id = 0;
    _fullname = "";
    _degree = "";
    _numOfCourses = 0;
}

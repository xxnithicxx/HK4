#pragma once

#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
    static bool isTime(string time)
    {
        if (time.size() > 5)
            return false;

        string hour = time.substr(0, 2);
        string minutes = time.substr(3, 5);
        int ihour, imin;

        try
        {
            ihour = stoi(hour);
            imin = stoi(minutes);
        }
        catch (const std::exception &e)
        {
            return false;
        }

        if (ihour < 0 || ihour > 23)
            return false;

        if (imin < 0 || imin > 59)
            return false;

        return true;
    };
};
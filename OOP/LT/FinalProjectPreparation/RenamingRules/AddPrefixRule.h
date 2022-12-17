#pragma once

#include <string>
#include <sstream>
using namespace std;

class AddPrefixRule
{
private:
    string _prefix;

public:
    void setPrefix(string);
    string Rename(string);
};

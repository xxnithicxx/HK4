#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace Utils
{
    namespace String
    {
        vector<string> split(string str, string delimiter)
        {
            vector<string> tokens;
            size_t pos = 0;
            string token;
            pos = str.find(delimiter);

            token = str.substr(0, pos);
            tokens.push_back(token);
            str.erase(0, pos + delimiter.length());

            tokens.push_back(str);
            return tokens;
        }
    }
}
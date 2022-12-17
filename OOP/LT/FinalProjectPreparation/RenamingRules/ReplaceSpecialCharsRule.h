#pragma once
#include <vector>
#include <string>
using namespace std;
class ReplaceSpecialCharsRule;

class ReplaceSpecialCharsRule
{
private:
    vector<string> _flag;
    string _replace;

public:
    vector<string> &specialChars();
    void setReplacement(string);
    string Rename(string);
};
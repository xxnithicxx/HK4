#include "ReplaceSpecialCharsRule.h"

vector<string> &ReplaceSpecialCharsRule::specialChars()
{
    return _flag;
}

void ReplaceSpecialCharsRule::setReplacement(string replace)
{
    this->_replace = replace;
}

string ReplaceSpecialCharsRule::Rename(string str)
{
    for (int i = 0; i < _flag.size(); i++)
    {
        auto pos = str.find(_flag[i]);

        while (pos != str.npos)
        {
            str.replace(pos, _replace.size(), _replace);
            pos = str.find(_flag[i]);
        }
    }
    
    return str;
}
#include "AddPrefixRule.h"

void AddPrefixRule::setPrefix(string pre)
{
    this->_prefix = pre;
}

string AddPrefixRule::Rename(string str)
{
    stringstream ss;
    ss << this->_prefix << " " << str;
    return ss.str();
}
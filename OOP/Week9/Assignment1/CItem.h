#pragma once

#include <iostream>
using namespace std;

// Common abstract class for CFolder and CFile
class CItem
{
protected:
    string name;
    bool isHidden;
    bool isReadOnly;

public:
    string getName()
    {
        return name;
    }
    bool getIsHidden()
    {
        return isHidden;
    }
    virtual int getSize() = 0;
    
    void setIsReadOnly(bool isReadOnly)
    {
        this->isReadOnly = isReadOnly;
    }


public:
    virtual void print(bool isPrintHiddenItems = false) = 0;
    virtual CItem *removeByName(string name) = 0;
    virtual CItem *findByName(string name) = 0;
    virtual void setHidden(bool isHidden, bool isAlsoApplyToChildren = true) = 0;
};
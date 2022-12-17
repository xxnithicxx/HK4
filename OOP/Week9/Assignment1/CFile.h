#pragma once

#include <iostream>
#include <vector>
#include "CItem.h"
using namespace std;

class CFile : public CItem
{
private:
    int size;

public:
    int getSize();

public:
    CFile(string name, int size, bool readOnly = false);
    CFile();
    CItem *removeByName(string name);
    CItem *findByName(string name);
    void setHidden(bool isHidden, bool isAlsoApplyToChildren = true);
    void print(bool isPrintHiddenItems = false);
};
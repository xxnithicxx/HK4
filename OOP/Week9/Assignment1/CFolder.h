#pragma once

#include <iostream>
#include <vector>
#include "CItem.h"
using namespace std;

class CFolder : public CItem
{
private:
    vector<CItem *> items;

public:
    int getSize();

public:
    CFolder(string name, bool isReadOnly = false);
    void add(CItem *item);
    CItem *removeByName(string name);
    CItem *findByName(string name);
    void setHidden(bool isHidden, bool isAlsoApplyToChildren = true);
    void print(bool isPrintHiddenItems = false);
};
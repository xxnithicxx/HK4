#include "CFolder.h"

CFolder::CFolder(string name , bool isReadOnly)
{
    this->name = name;
    this->isHidden = false;
    this->isReadOnly = isReadOnly;
}

void CFolder::add(CItem *item)
{
    items.push_back(item);
}

CItem *CFolder::removeByName(string name)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->getName() == name)
        {
            CItem *p = items[i];
            items.erase(items.begin() + i);
            return p;
        }

        CItem *p = items[i]->removeByName(name);
        if (p != NULL)
        {
            return p;
        }
    }
    return NULL;
}

CItem *CFolder::findByName(string name)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->getName() == name)
        {
            return items[i];
        }

        CItem *p = items[i]->findByName(name);
        if (p != NULL)
        {
            return p;
        }
    }
    return NULL;
}

void CFolder::setHidden(bool isHidden, bool isAlsoApplyToChildren)
{
    this->isHidden = isHidden;
    if (isAlsoApplyToChildren)
    {
        for (int i = 0; i < items.size(); i++)
        {
            items[i]->setHidden(isHidden, isAlsoApplyToChildren);
        }
    }
}

int CFolder::getSize()
{
    int size = 0;
    for (int i = 0; i < items.size(); i++)
    {
        size += items[i]->getSize();
    }
    return size;
}

void CFolder::print(bool isPrintHiddenItems)
{
    if (isPrintHiddenItems || !isHidden)
    {
        cout << "Folder: " << name << endl;
        for (int i = 0; i < items.size(); i++)
        {
            items[i]->print(isPrintHiddenItems);
        }
    }
}
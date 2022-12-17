#include "CFile.h"

CFile::CFile(string name, int size, bool readOnly)
{
    this->name = name;
    this->size = size;
    this->isHidden = false;
    this->isReadOnly = readOnly;
}

CItem *CFile::removeByName(string name)
{
    if (this->name == name)
    {
        return this;
    }
    return NULL;
}

CItem *CFile::findByName(string name)
{
    if (this->name == name)
    {
        return this;
    }
    return NULL;
}

void CFile::setHidden(bool isHidden, bool isAlsoApplyToChildren)
{
    this->isHidden = isHidden;
}

int CFile::getSize()
{
    return size;
}

void CFile::print(bool isPrintHiddenItems)
{
    if (isPrintHiddenItems || !isHidden)
    {
        cout << "File: " << name << " (" << size << " bytes)" << endl;
    }
}

CFile::CFile(){
    this->name = "untitled";
    this->isReadOnly = true;
    this->isHidden = false;
}
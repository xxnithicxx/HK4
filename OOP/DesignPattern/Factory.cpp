#include <iostream>
using namespace std;

class Mouse
{
public:
    virtual void click() = 0;
};

class DellMouse : public Mouse
{
public:
    void click()
    {
        cout << "Dell Mouse" << endl;
    }
};

class HpMouse : public Mouse
{
public:
    void click()
    {
        cout << "Hp Mouse" << endl;
    }
};

int main()
{
    Mouse* mouse = new DellMouse();
    mouse->click();
    mouse = new HpMouse();
    mouse->click();
    return 0;
}
#include <iostream>
using namespace std;

class Shape // Prototype interface (or abstract class)
{
protected:
    int x, y;
    int color;

public:
    Shape(const Shape &source) // Copy constructor
    {
        x = source.x;
        y = source.y;
        color = source.color;
    }

    Shape(int x, int y, int color) : x(x), y(y), color(color) {}

    virtual void draw() = 0;
    virtual Shape *clone() = 0;
};

class Rectangle : public Shape // Concrete Prototype
{
private:
    int width, height;

public:
    Rectangle(int x, int y, int color, int width, int height) : Shape(x, y, color), width(width), height(height) {}
    Rectangle(const Rectangle &source) : Shape(source), width(source.width), height(source.height) {}

    Shape *clone() override
    {
        return new Rectangle(*this);
    }

    void draw() override
    {
        cout << "Rectangle drawn at (" << x << ", " << y << ") with color " << color << " and dimensions " << width << "x" << height << endl;
    }
};

class Circle : public Shape // Concrete Prototype
{
private:
    int radius;

public:
    Circle(int x, int y, int color, int radius) : Shape(x, y, color), radius(radius) {}
    Circle(const Circle &source) : Shape(source), radius(source.radius) {}

    Shape *clone() override
    {
        return new Circle(*this);
    }

    void draw() override
    {
        cout << "Circle drawn at (" << x << ", " << y << ") with color " << color << " and radius " << radius << endl;
    }
};

int main(){
    Shape *rect = new Rectangle(10, 20, 0xFF0000, 100, 200);
    Shape *circle = new Circle(30, 40, 0x00FF00, 50);

    rect->draw();
    circle->draw();

    Shape *rect2 = rect->clone();
    Shape *circle2 = circle->clone();

    rect2->draw();
    circle2->draw();

    delete rect;
    delete circle;
    delete rect2;
    delete circle2;

    return 0;
}
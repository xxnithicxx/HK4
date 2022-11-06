#pragma once

class Point {
private:
    int _x;
    int _y;

public:
    void setX(int x) { _x = x; }
    void setY(int y) { _y = y; }

public:
    void Input();
    void Output();
    double Distance(Point other);
    int DistanceToOx();
    int DistanceToOy();
};
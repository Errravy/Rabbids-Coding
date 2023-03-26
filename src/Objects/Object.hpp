#pragma once

#include <iostream>

using namespace std;

class Object
{
private:
    int x;
    int y;

public:
    int getX();
    int getY();
    void setX(int);
    void setY(int);

    virtual void print() = 0;
};
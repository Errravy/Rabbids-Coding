#pragma once

#include <iostream>

class IObjects
{
protected:
    std::string _objectSymbol;
    int _x;
    int _y;

public:
    virtual void setPositionX(int) = 0;
    virtual void setPositionY(int) = 0;
    virtual void setPosition(int, int) = 0;
    virtual std::pair<int, int> getPosition() = 0;
    virtual std::string getObjectSymbol() = 0;
};

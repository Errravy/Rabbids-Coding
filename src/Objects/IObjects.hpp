#pragma once

#ifndef IOBJECTS_HPP
#define IOBJECTS_HPP

#include <iostream>

#include "../Playspace/Cell.hpp"

class IObjects
{
private:
    std::string _objectSymbol;
    int _x;
    int _y;
    Cell _cell;
    bool _isSucked;

public:
    virtual bool isSucked() = 0;
    virtual void setPositionX(int x) = 0;
    virtual void setPositionY(int y) = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual std::pair<int, int> getPosition() = 0;
    virtual std::string getObjectSymbol() = 0;
};

#endif
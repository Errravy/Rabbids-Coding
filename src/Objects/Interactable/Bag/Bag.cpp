#include "Bag.hpp"
#include <iostream>

Bag::Bag()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
}

void Bag::setPositionX(int x)
{
    _x = x;
}

void Bag::setPositionY(int y)
{
    _y = y;
}

void Bag::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> Bag::getPosition()
{
    return std::make_pair(_x, _y);
}

void Bag::react()
{
    std::cout << "Bag activated!" << std::endl;
}

bool Bag::isSucked()
{
    return _isSucked;
}

std::string Bag::getObjectSymbol()
{
    return objectSymbol;
}
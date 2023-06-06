#include "Bag.hpp"

Bag::Bag()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
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

std::string Bag::getObjectSymbol()
{
    return _objectSymbol;
}

void Bag::react()
{
    std::cout << "Bag activated!" << std::endl;
}
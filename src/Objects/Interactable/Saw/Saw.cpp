#include "Saw.hpp"

Saw::Saw()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
}

void Saw::setPositionX(int x)
{
    _x = x;
}

void Saw::setPositionY(int y)
{
    _y = y;
}

void Saw::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> Saw::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string Saw::getObjectSymbol()
{
    return _objectSymbol;
}

void Saw::react()
{
    std::cout << "Saw activated!" << std::endl;
}
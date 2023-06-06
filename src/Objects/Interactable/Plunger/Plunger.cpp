#include "Plunger.hpp"

Plunger::Plunger()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
}

void Plunger::setPositionX(int x)
{
    _x = x;
}

void Plunger::setPositionY(int y)
{
    _y = y;
}

void Plunger::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> Plunger::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string Plunger::getObjectSymbol()
{
    return _objectSymbol;
}

void Plunger::react()
{
    std::cout << "Plunger activated!" << std::endl;
}
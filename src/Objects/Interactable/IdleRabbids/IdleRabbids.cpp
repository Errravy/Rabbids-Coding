#include "IdleRabbids.hpp"

IdleRabbids::IdleRabbids()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
}

void IdleRabbids::setPositionX(int x)
{
    _x = x;
}

void IdleRabbids::setPositionY(int y)
{
    _y = y;
}

void IdleRabbids::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> IdleRabbids::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string IdleRabbids::getObjectSymbol()
{
    return _objectSymbol;
}

void IdleRabbids::react()
{
    std::cout << "IdleRabbids activated!" << std::endl;
}
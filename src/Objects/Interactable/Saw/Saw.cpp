#include "Saw.hpp"

Saw::Saw()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
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

void Saw::react()
{
    std::cout << "IdleRabbid activated!" << std::endl;
}

std::pair<int, int> Saw::getPosition()
{
    return std::make_pair(_x, _y);
}

bool Saw::isSucked()
{
    return _isSucked;
}

std::string Saw::getObjectSymbol()
{
    return objectSymbol;
}
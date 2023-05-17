#include "Tas.hpp"

Tas::Tas()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
}

void Tas::setPositionX(int x)
{
    _x = x;
}

void Tas::setPositionY(int y)
{
    _y = y;
}

void Tas::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void Tas::react()
{
    std::cout << "IdleRabbid activated!" << std::endl;
}

std::pair<int, int> Tas::getPosition()
{
    return std::make_pair(_x, _y);
}

bool Tas::isSucked()
{
    return _isSucked;
}

std::string Tas::getObjectSymbol()
{
    return objectSymbol;
}
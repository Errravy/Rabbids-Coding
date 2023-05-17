#include "Tissue.hpp"

Tissue::Tissue()
{
    _x = 0;
    _y = 0;
    _isSucked = false;
}

void Tissue::setPositionX(int x)
{
    _x = x;
}

void Tissue::setPositionY(int y)
{
    _y = y;
}

void Tissue::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void Tissue::react()
{
    std::cout << "IdleRabbid activated!" << std::endl;
}

std::pair<int, int> Tissue::getPosition()
{
    return std::make_pair(_x, _y);
}

bool Tissue::isSucked()
{
    return _isSucked;
}

std::string Tissue::getObjectSymbol()
{
    return objectSymbol;
}
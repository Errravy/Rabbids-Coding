#include "Tissue.hpp"

Tissue::Tissue()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
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

std::pair<int, int> Tissue::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string Tissue::getObjectSymbol()
{
    return _objectSymbol;
}

void Tissue::react()
{
    std::cout << "Tissue activated!" << std::endl;
}
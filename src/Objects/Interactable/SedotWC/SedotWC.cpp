#include "SedotWC.hpp"

SedotWC::SedotWC()
{
    _x = 0;
    _y = 0;
}

void SedotWC::setPositionX(int x)
{
    _x = x;
}

void SedotWC::setPositionY(int y)
{
    _y = y;
}

void SedotWC::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void SedotWC::react()
{
    std::cout << "SedotWC activated!" << std::endl;
}

std::pair<int, int> SedotWC::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string SedotWC::getObjectSymbol()
{
    return _objectSymbol;
}
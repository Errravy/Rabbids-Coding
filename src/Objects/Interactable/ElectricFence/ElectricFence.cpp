#include "ElectricFence.hpp"

ElectricFence::ElectricFence()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
}

void ElectricFence::setPositionX(int x)
{
    _x = x;
}

void ElectricFence::setPositionY(int y)
{
    _y = y;
}

void ElectricFence::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> ElectricFence::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string ElectricFence::getObjectSymbol()
{
    return _objectSymbol;
}

void ElectricFence::react()
{
    std::cout << "ElectricFence activated!" << std::endl;
}
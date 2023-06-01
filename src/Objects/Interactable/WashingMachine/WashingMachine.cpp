#include "WashingMachine.hpp"

WashingMachine::WashingMachine()
{
    _x = 0;
    _y = 0;
    _objectSymbol = "I";
}

void WashingMachine::setPositionX(int x)
{
    _x = x;
}

void WashingMachine::setPositionY(int y)
{
    _y = y;
}

void WashingMachine::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

std::pair<int, int> WashingMachine::getPosition()
{
    return std::make_pair(_x, _y);
}

std::string WashingMachine::getObjectSymbol()
{
    return _objectSymbol;
}

void WashingMachine::react()
{
    std::cout << "WashingMachine activated!" << std::endl;
}